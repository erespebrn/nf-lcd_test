/*********************
 *      INCLUDES
 *********************/

#include "lvgl_port_touch.h"
#include "main.h"
#include "i2c.h"
#include "stm32746g_discovery_ts.h"
/**********************
 *  STATIC VARIABLES
 **********************/

static volatile uint8_t touch_irq = 0;

/**********************
 *  STATIC PROTOTYPES
 **********************/

static void
lvgl_touchscreen_read (lv_indev_drv_t *indev, lv_indev_data_t *data);

/**********************
 *   GLOBAL FUNCTIONS
 **********************/

void
lvgl_touchscreen_init (void)
{
  static lv_indev_drv_t indev_drv;

  BSP_TS_Init(480, 272);

  /* basic LVGL driver initialization */
  lv_indev_drv_init(&indev_drv);
  indev_drv.type = LV_INDEV_TYPE_POINTER;
  indev_drv.read_cb = lvgl_touchscreen_read;

  /* register the driver in LVGL */
  lv_indev_drv_register(&indev_drv);
}

/**********************
 *   STATIC FUNCTIONS
 **********************/

static void
lvgl_touchscreen_read (lv_indev_drv_t  *indev,
                       lv_indev_data_t *data)
{
  TS_StateTypeDef state = { 0 };

  BSP_TS_GetState(&state);

  if (state.touchDetected)
  {
    data->point.x = state.touchX[0];
    data->point.y = state.touchY[0];

      data->state = LV_INDEV_STATE_PRESSED;
  }
  else
  {
    data->state = LV_INDEV_STATE_RELEASED;
  }
}

void
HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin)
{
//  if (GPIO_Pin == CTP_INT_Pin)
//    touch_irq = 1;
}
