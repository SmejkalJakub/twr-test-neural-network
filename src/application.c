// Tower Kit documentation https://tower.hardwario.com/
// SDK API description https://sdk.hardwario.com/
// Forum https://forum.hardwario.com/

#include <application.h>
#include <ai_platform.h>

/*#include <network.h>
#include <network_data.h>*/

#include <network_temperature.h>
#include <network_temperature_data.h>

#include <network_humidity.h>
#include <network_humidity_data.h>

#include <stm32l0xx_hal_crc.h>

// LED instance
twr_led_t led;

// Button instance
twr_button_t button;

struct tm datetime;

// Thermometer instance
twr_tmp112_t tmp112;
uint16_t button_click_count = 0;

float lastTemperature = 0;
float lastHumidity = 0;

ai_handle network_temperature;
float aiTemperatureInData[AI_NETWORK_TEMPERATURE_IN_1_SIZE];
float aiTemperatureOutData[AI_NETWORK_TEMPERATURE_OUT_1_SIZE];

ai_u8 activations_temperature[AI_NETWORK_TEMPERATURE_DATA_ACTIVATIONS_SIZE];

ai_buffer *ai_temperature_input;
ai_buffer *ai_temperature_output;

static void AI_Temperature_Init(void);
static void AI_Temperature_Run(float *pIn, float *pOut);

ai_handle network_humidity;
float aiHumidityInData[AI_NETWORK_HUMIDITY_IN_1_SIZE];
float aiHumidityOutData[AI_NETWORK_HUMIDITY_OUT_1_SIZE];

ai_u8 activations_humidity[AI_NETWORK_HUMIDITY_DATA_ACTIVATIONS_SIZE];

ai_buffer *ai_humidity_input;
ai_buffer *ai_humidity_output;

static void AI_Humidity_Init(void);
static void AI_Humidity_Run(float *pIn, float *pOut);

static void AI_Temperature_Init(void)
{
    ai_error err;

    /* Create a local array with the addresses of the activations buffers */
    const ai_handle act_addr[] = {activations_temperature};
    /* Create an instance of the model */
    err = ai_network_temperature_create_and_init(&network_temperature, act_addr, NULL);
    if (err.type != AI_ERROR_NONE)
    {
        twr_log_error("ai_network_create_and_init error - type=%d code=%d", err.type, err.code);
        return;
    }
    ai_temperature_input = ai_network_temperature_inputs_get(network_temperature, NULL);
    ai_temperature_output = ai_network_temperature_outputs_get(network_temperature, NULL);
}

static void AI_Temperature_Run(float *pIn, float *pOut)
{
    ai_i32 batch;
    ai_error err;

    /* Update IO handlers with the data payload */
    ai_temperature_input[0].data = AI_HANDLE_PTR(pIn);
    ai_temperature_output[0].data = AI_HANDLE_PTR(pOut);

    batch = ai_network_temperature_run(network_temperature, ai_temperature_input, ai_temperature_output);
    if (batch != 1)
    {
        err = ai_network_temperature_get_error(network_temperature);
        twr_log_error("AI ai_network_run error - type=%d code=%d", err.type, err.code);
        return;
    }
}

static void AI_Humidity_Init(void)
{
    ai_error err;

    /* Create a local array with the addresses of the activations buffers */
    const ai_handle act_addr[] = {activations_humidity};
    /* Create an instance of the model */
    err = ai_network_humidity_create_and_init(&network_humidity, act_addr, NULL);
    if (err.type != AI_ERROR_NONE)
    {
        twr_log_error("ai_network_create_and_init error - type=%d code=%d", err.type, err.code);
        return;
    }
    ai_humidity_input = ai_network_humidity_inputs_get(network_humidity, NULL);
    ai_humidity_output = ai_network_humidity_outputs_get(network_humidity, NULL);
}

static void AI_Humidity_Run(float *pIn, float *pOut)
{
    ai_i32 batch;
    ai_error err;

    /* Update IO handlers with the data payload */
    ai_humidity_input[0].data = AI_HANDLE_PTR(pIn);
    ai_humidity_output[0].data = AI_HANDLE_PTR(pOut);

    batch = ai_network_humidity_run(network_humidity, ai_humidity_input, ai_humidity_output);
    if (batch != 1)
    {
        err = ai_network_humidity_get_error(network_humidity);
        twr_log_error("AI ai_network_run error - type=%d code=%d", err.type, err.code);
        return;
    }
}

// Button event callback
void button_event_handler(twr_button_t *self, twr_button_event_t event, void *event_param)
{
    // Log button event
    twr_log_info("APP: Button event: %i", event);

    // Check event source
    if (event == TWR_BUTTON_EVENT_CLICK)
    {
        // Toggle LED pin state
        twr_led_set_mode(&led, TWR_LED_MODE_TOGGLE);

        // Publish message on radio
        button_click_count++;
        twr_radio_pub_push_button(&button_click_count);
    }
}

void climate_module_event_handler(twr_module_climate_event_t event, void *event_param)
{
    if (event == TWR_MODULE_CLIMATE_EVENT_UPDATE_THERMOMETER)
    {
        float celsius;
        if (twr_module_climate_get_temperature_celsius(&celsius))
        {
            twr_rtc_get_datetime(&datetime);

            int year = datetime.tm_year + 1900;

            ((ai_float *)aiTemperatureInData)[0] = (ai_float)year;
            ((ai_float *)aiTemperatureInData)[1] = (ai_float)datetime.tm_mon;
            ((ai_float *)aiTemperatureInData)[2] = (ai_float)datetime.tm_mday;
            ((ai_float *)aiTemperatureInData)[3] = (ai_float)datetime.tm_hour;
            ((ai_float *)aiTemperatureInData)[4] = (ai_float)datetime.tm_min;
            ((ai_float *)aiTemperatureInData)[5] = (ai_float)datetime.tm_sec;
            ((ai_float *)aiTemperatureInData)[6] = (ai_float)lastTemperature;
            ((ai_float *)aiTemperatureInData)[7] = (ai_float)lastHumidity;

            AI_Temperature_Run(aiTemperatureInData, aiTemperatureOutData);

            float y_val = ((ai_float *)aiTemperatureOutData)[0];

            twr_log_debug("------------------------");
            twr_log_debug("APP: predicted temperature: %f", y_val);

            lastTemperature = celsius;

            twr_log_debug("APP: temperature: %.2f", celsius);
            twr_log_debug("------------------------");

            char buffer[80];
            sprintf(buffer, "{\\\"predicted\\\": %.2f, \\\"actual\\\": %.2f}", y_val, celsius);
            twr_radio_pub_string("temperature", buffer);

        }
    }
    else if (event == TWR_MODULE_CLIMATE_EVENT_UPDATE_HYGROMETER)
    {
        float humidity;
        if (twr_module_climate_get_humidity_percentage(&humidity))
        {
            twr_rtc_get_datetime(&datetime);

            int year = datetime.tm_year + 1900;

            ((ai_float *)aiHumidityInData)[0] = (ai_float)year;
            ((ai_float *)aiHumidityInData)[1] = (ai_float)datetime.tm_mon;
            ((ai_float *)aiHumidityInData)[2] = (ai_float)datetime.tm_mday;
            ((ai_float *)aiHumidityInData)[3] = (ai_float)datetime.tm_hour;
            ((ai_float *)aiHumidityInData)[4] = (ai_float)datetime.tm_min;
            ((ai_float *)aiHumidityInData)[5] = (ai_float)datetime.tm_sec;
            ((ai_float *)aiHumidityInData)[6] = (ai_float)lastHumidity;
            ((ai_float *)aiHumidityInData)[7] = (ai_float)lastTemperature;

            AI_Humidity_Run(aiHumidityInData, aiHumidityOutData);

            float y_val = ((ai_float *)aiHumidityOutData)[0];

            twr_log_debug("------------------------");
            twr_log_debug("APP: predicted humidity: %f", y_val);

            lastHumidity = humidity;

            twr_log_debug("APP: humidity: %.2f", humidity);
            twr_log_debug("------------------------");

            // Create json string with predicted humidity and actual humidity
            char buffer[80];
            sprintf(buffer, "{\\\"predicted\\\": %.2f, \\\"actual\\\": %.2f}", y_val, humidity);
            twr_radio_pub_string("humidity", buffer);
        }
    }
}

// Application initialization function which is called once after boot
void application_init(void)
{
    /*struct tm datetime;

    datetime.tm_hour = 22;
    datetime.tm_min = 50;
    datetime.tm_sec = 00;

    datetime.tm_mon = 03;
    datetime.tm_mday = 19;
    datetime.tm_year = 123;*/

    // twr_rtc_set_datetime(&datetime, 0);

    __HAL_RCC_CRC_CLK_ENABLE();

    // Initialize logging
    twr_log_init(TWR_LOG_LEVEL_DUMP, TWR_LOG_TIMESTAMP_ABS);

    AI_Temperature_Init();
    AI_Humidity_Init();

    // Initialize LED
    twr_led_init(&led, TWR_GPIO_LED, false, 0);
    twr_led_pulse(&led, 2000);

    // Initialize button
    twr_button_init(&button, TWR_GPIO_BUTTON, TWR_GPIO_PULL_DOWN, 0);
    twr_button_set_event_handler(&button, button_event_handler, NULL);

    twr_module_climate_init();
    twr_module_climate_set_event_handler(climate_module_event_handler, NULL);
    twr_module_climate_set_update_interval_thermometer(10000);
    twr_module_climate_set_update_interval_hygrometer(10000);
    twr_module_climate_set_update_interval_lux_meter(10000);
    twr_module_climate_set_update_interval_barometer(10000);
    twr_module_climate_measure_all_sensors();

    // Initialize radio
    twr_radio_init(TWR_RADIO_MODE_NODE_SLEEPING);
    // Send radio pairing request
    twr_radio_pairing_request("skeleton", FW_VERSION);


    twr_rtc_get_datetime(&datetime);
    twr_log_debug("$DATE: \"%d-%02d-%02dT%02d:%02d:%02dZ\"", datetime.tm_year + 1900, datetime.tm_mon, datetime.tm_mday, datetime.tm_hour, datetime.tm_min, datetime.tm_sec);
}
