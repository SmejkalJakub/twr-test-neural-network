/**
  ******************************************************************************
  * @file    stm32l0xx_hal_pcd_ex.c
  * @author  MCD Application Team
  * @version V1.8.0
  * @date    25-November-2016
  * @brief   Extended PCD HAL module driver.
  *          This file provides firmware functions to manage the following
  *          functionalities of the USB Peripheral Controller:
  *           + Configururation of the PMA for EP
  *
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; COPYRIGHT(c) 2016 STMicroelectronics</center></h2>
  *
  * Redistribution and use in source and binary forms, with or without modification,
  * are permitted provided that the following conditions are met:
  *   1. Redistributions of source code must retain the above copyright notice,
  *      this list of conditions and the following disclaimer.
  *   2. Redistributions in binary form must reproduce the above copyright notice,
  *      this list of conditions and the following disclaimer in the documentation
  *      and/or other materials provided with the distribution.
  *   3. Neither the name of STMicroelectronics nor the names of its contributors
  *      may be used to endorse or promote products derived from this software
  *      without specific prior written permission.
  *
  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
  * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
  * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
  * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
  * CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
  * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
  * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
  *
  ******************************************************************************
  */

#if !defined(STM32L011xx) && !defined(STM32L021xx) && !defined (STM32L031xx) && !defined (STM32L041xx) && !defined (STM32L051xx) && !defined (STM32L061xx) && !defined (STM32L071xx) && !defined (STM32L081xx)
/* Includes ------------------------------------------------------------------*/
#include <stm32l0xx_hal.h>
#ifdef HAL_PCD_MODULE_ENABLED
/** @addtogroup STM32L0xx_HAL_Driver
  * @{
  */

/** @addtogroup PCDEx
  * @brief PCDEx HAL module driver
  * @{
  */



/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/* Private function prototypes -----------------------------------------------*/
/* Private functions ---------------------------------------------------------*/


/** @addtogroup PCDEx_Exported_Functions PCDEx Exported Functions
  * @{
  */

/** @addtogroup PCDEx__Exported_Functions_Group1
 *  @brief    Initialization and Configuration functions
 *
@verbatim
 ===============================================================================
                 ##### Peripheral extended features functions #####
 ===============================================================================
@endverbatim
  * @{
  */

/**
  * @brief Configure PMA for EP
  * @param  hpcd : Device instance
  * @param  ep_addr: endpoint address
  * @param  ep_kind: endpoint Kind
  *                  USB_SNG_BUF: Single Buffer used
  *                  USB_DBL_BUF: Double Buffer used
  * @param  pmaadress: EP address in The PMA: In case of single buffer endpoint
  *                   this parameter is 16-bit value providing the address
  *                   in PMA allocated to endpoint.
  *                   In case of double buffer endpoint this parameter
  *                   is a 32-bit value providing the endpoint buffer 0 address
  *                   in the LSB part of 32-bit value and endpoint buffer 1 address
  *                   in the MSB part of 32-bit value.
  * @retval : status
  */


HAL_StatusTypeDef  HAL_PCDEx_PMAConfig(PCD_HandleTypeDef *hpcd,
                        uint16_t ep_addr,
                        uint16_t ep_kind,
                        uint32_t pmaadress)

{
  PCD_EPTypeDef *ep;

  /* initialize ep structure*/
  if ((0x80U & ep_addr) == 0x80U)
  {
    ep = &hpcd->IN_ep[ep_addr & 0x7FU];
  }
  else
  {
    ep = &hpcd->OUT_ep[ep_addr];
  }

  /* Here we check if the endpoint is single or double Buffer*/
  if (ep_kind == PCD_SNG_BUF)
  {
    /*Single Buffer*/
    ep->doublebuffer = 0U;
    /*Configure te PMA*/
    ep->pmaadress = (uint16_t)pmaadress;
  }
  else /*USB_DBL_BUF*/
  {
    /*Double Buffer Endpoint*/
    ep->doublebuffer = 1U;
    /*Configure the PMA*/
    ep->pmaaddr0 =  pmaadress & 0xFFFFU;
    ep->pmaaddr1 =  (pmaadress & 0xFFFF0000U) >> 16U;
  }

  return HAL_OK;
}

/**
  * @brief  Activate BatteryCharging feature.
  * @param  hpcd: PCD handle
  * @retval HAL status
  */
HAL_StatusTypeDef HAL_PCDEx_ActivateBCD(PCD_HandleTypeDef *hpcd)
{
  USB_TypeDef *USBx = hpcd->Instance;
  hpcd->battery_charging_active = ENABLE;

  USBx->BCDR |= (USB_BCDR_BCDEN);
  /* Enable DCD : Data Contact Detect */
  USBx->BCDR |= (USB_BCDR_DCDEN);

  return HAL_OK;
}

/**
  * @brief  Deactivate BatteryCharging feature.
  * @param  hpcd: PCD handle
  * @retval HAL status
  */
HAL_StatusTypeDef HAL_PCDEx_DeActivateBCD(PCD_HandleTypeDef *hpcd)
{
  USB_TypeDef *USBx = hpcd->Instance;
  hpcd->battery_charging_active = DISABLE;

  USBx->BCDR &= ~(USB_BCDR_BCDEN);
  return HAL_OK;
}

/**
  * @brief  Handle BatteryCharging Process.
  * @param  hpcd: PCD handle
  * @retval HAL status
  */
void HAL_PCDEx_BCD_VBUSDetect(PCD_HandleTypeDef *hpcd)
{
  USB_TypeDef *USBx = hpcd->Instance;
  uint32_t tickstart = HAL_GetTick();

  /* Wait Detect flag or a timeout is happen*/
  while ((USBx->BCDR & USB_BCDR_DCDET) == 0)
  {
    /* Check for the Timeout */
    if((HAL_GetTick() - tickstart ) > 1000)
    {
      HAL_PCDEx_BCD_Callback(hpcd, PCD_BCD_ERROR);
      return;
    }
  }

  HAL_Delay(300);

  /* Data Pin Contact ? Check Detect flag */
  if (USBx->BCDR & USB_BCDR_DCDET)
  {
    HAL_PCDEx_BCD_Callback(hpcd, PCD_BCD_CONTACT_DETECTION);
  }
  /* Primary detection: checks if connected to Standard Downstream Port
  (without charging capability) */
  USBx->BCDR &= ~(USB_BCDR_DCDEN);
  USBx->BCDR |= (USB_BCDR_PDEN);
  HAL_Delay(300);

  /* If Charger detect ? */
  if (USBx->BCDR & USB_BCDR_PDET)
  {
    /* Start secondary detection to check connection to Charging Downstream
    Port or Dedicated Charging Port */
    USBx->BCDR &= ~(USB_BCDR_PDEN);
    USBx->BCDR |= (USB_BCDR_SDEN);
    HAL_Delay(300);

    /* If CDP ? */
    if (USBx->BCDR & USB_BCDR_SDET)
    {
      /* Dedicated Downstream Port DCP */
      HAL_PCDEx_BCD_Callback(hpcd, PCD_BCD_DEDICATED_CHARGING_PORT);
    }
    else
    {
      /* Charging Downstream Port CDP */
      HAL_PCDEx_BCD_Callback(hpcd, PCD_BCD_CHARGING_DOWNSTREAM_PORT);
    }
  }
  else
  {
    /* Standard Downstream Port */
    HAL_PCDEx_BCD_Callback(hpcd, PCD_BCD_STD_DOWNSTREAM_PORT);
  }
  /* Battery Charging capability discovery finished
  Start Enumeration*/
  HAL_PCDEx_BCD_Callback(hpcd, PCD_BCD_DISCOVERY_COMPLETED);
}

/**
  * @brief  Activate LPM feature.
  * @param  hpcd: PCD handle
  * @retval HAL status
  */
HAL_StatusTypeDef HAL_PCDEx_ActivateLPM(PCD_HandleTypeDef *hpcd)
{

  USB_TypeDef *USBx = hpcd->Instance;
  hpcd->lpm_active = ENABLE;
  hpcd->LPM_State = LPM_L0;

  USBx->LPMCSR |= (USB_LPMCSR_LMPEN);
  USBx->LPMCSR |= (USB_LPMCSR_LPMACK);


  return HAL_OK;
}

/**
  * @brief  Deactivate LPM feature.
  * @param  hpcd: PCD handle
  * @retval HAL status
  */
HAL_StatusTypeDef HAL_PCDEx_DeActivateLPM(PCD_HandleTypeDef *hpcd)
{
  USB_TypeDef *USBx = hpcd->Instance;

  hpcd->lpm_active = DISABLE;

  USBx->LPMCSR &= ~ (USB_LPMCSR_LMPEN);
  USBx->LPMCSR &= ~ (USB_LPMCSR_LPMACK);

  return HAL_OK;
}

/**
  * @brief  Send LPM message to user layer callback.
  * @param  hpcd: PCD handle
  * @param  msg: LPM message
  * @retval HAL status
  */
__weak void HAL_PCDEx_LPM_Callback(PCD_HandleTypeDef *hpcd, PCD_LPM_MsgTypeDef msg)
{
  /* Prevent unused argument(s) compilation warning */
  UNUSED(hpcd);
  UNUSED(msg);

  /* NOTE : This function should not be modified, when the callback is needed,
            the HAL_PCDEx_LPM_Callback could be implemented in the user file
   */
}

/**
  * @brief  Send BatteryCharging message to user layer callback.
  * @param  hpcd: PCD handle
  * @param  msg: LPM message
  * @retval HAL status
  */
__weak void HAL_PCDEx_BCD_Callback(PCD_HandleTypeDef *hpcd, PCD_BCD_MsgTypeDef msg)
{
  /* Prevent unused argument(s) compilation warning */
  UNUSED(hpcd);
  UNUSED(msg);

  /* NOTE : This function should not be modified, when the callback is needed,
            the HAL_PCDEx_BCD_Callback could be implemented in the user file
   */
}

/**
  * @}
  */


/**
  * @}
  */

/**
  * @}
  */

/**
  * @}
  */
#endif /* HAL_PCD_MODULE_ENABLED */
#endif /* #if !defined(STM32L011xx) && !defined(STM32L021xx) && !defined (STM32L031xx) && !defined (STM32L041xx) && !defined (STM32L051xx) && !defined (STM32L061xx) && !defined (STM32L071xx) && !defined (STM32L081xx) */
/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
