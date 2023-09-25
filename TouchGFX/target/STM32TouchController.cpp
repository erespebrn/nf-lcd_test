/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * File Name          : STM32TouchController.cpp
  ******************************************************************************
  * This file was created by TouchGFX Generator 4.22.0. This file is only
  * generated once! Delete this file from your project and re-generate code
  * using STM32CubeMX or change this file manually to update it.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2023 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* USER CODE BEGIN STM32TouchController */

#include <STM32TouchController.hpp>
#include "stm32746g_discovery_ts.h"
#include "main.h"

#define SCREEN_TIMEOUT_MS (3*60*1000)

extern I2C_HandleTypeDef hi2c3;

void STM32TouchController::init()
{
    /**
     * Initialize touch controller and driver
     *
     */
  BSP_TS_Init(480, 272);
}

bool STM32TouchController::sampleTouch(int32_t& x, int32_t& y)
{
    /**
     * By default sampleTouch returns false,
     * return true if a touch has been detected, otherwise false.
     *
     * Coordinates are passed to the caller by reference by x and y.
     *
     * This function is called by the TouchGFX framework.
     * By default sampleTouch is called every tick, this can be adjusted by HAL::setTouchSampleRate(int8_t);
     *
     */
  bool touchDetected = false;

  TS_StateTypeDef state = { 0 };

  BSP_TS_GetState(&state);

  if (state.touchDetected)
  {
      x = state.touchX[0];
      y = state.touchY[0];

      touchDetected = true;
  }

  if (!touchDetected)
  {
    if (!m_screenOff)
    {
      uint32_t timeoutCnt = HAL_GetTick() - m_screenOffCnt;

      if (timeoutCnt > SCREEN_TIMEOUT_MS)
      {
        m_screenOff = true;
        HAL_GPIO_WritePin(LCD_BL_CTRL_GPIO_Port, LCD_BL_CTRL_Pin, GPIO_PIN_RESET);
      }
    }
  }
  else
  {
    if (m_screenOff)
    {
      m_screenOff = false;
      HAL_GPIO_WritePin(LCD_BL_CTRL_GPIO_Port, LCD_BL_CTRL_Pin, GPIO_PIN_SET);
    }

    m_screenOffCnt = HAL_GetTick();
  }

  return touchDetected;
}

/* USER CODE END STM32TouchController */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
