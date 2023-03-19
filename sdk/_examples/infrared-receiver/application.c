#include <application.h>

// Infrared receive handler
static void ir_event_handler(twr_ir_rx_event_t event, void *param)
{
    (void) param;

    // Received command in NEC format
    if (event == TWR_IR_RX_NEC_FORMAT)
	{
        uint32_t nec_code;
        // Get latest command
        twr_ir_rx_get_code(&nec_code);

        // Print command
        twr_log_debug("nec_code: 0x%08x", nec_code);
	}
}

void application_init(void)
{
    twr_log_init(TWR_LOG_LEVEL_DUMP, TWR_LOG_TIMESTAMP_ABS);

    // Enable PLL for USB and infrared driver
    twr_system_pll_enable();

    // Init infrared driver
    twr_ir_rx_init();
    twr_ir_rx_set_event_handler(ir_event_handler, NULL);
}
