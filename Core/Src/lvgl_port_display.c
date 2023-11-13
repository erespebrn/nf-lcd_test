/*********************
 *      INCLUDES
 *********************/

#include "lvgl_port_display.h"
#include "main.h"
#include "ltdc.h"
#include "dma2d.h"
#include "../lv_conf_internal.h"
#include "lv_assert.h"
#include "lv_math.h"
#include "lv_types.h"

/**********************
 *  STATIC PROTOTYPES
 **********************/

static void disp_flush (lv_disp_drv_t*, const lv_area_t*, lv_color_t*);
static void disp_flush_complete (DMA2D_HandleTypeDef*);

/**********************
 *  STATIC VARIABLES
 **********************/

static lv_disp_drv_t disp_drv;
static lv_disp_draw_buf_t disp_buf;

#define LVGL_BUFFER_1_ADDR_AT_SDRAM	(0xC01F4000)
#define LVGL_BUFFER_2_ADDR_AT_SDRAM	(0xC03E8000)
#define BUF_W 20
#define BUF_H 10
/**********************
 *   GLOBAL FUNCTIONS
 **********************/

void lvgl_display_init(void)
{
  /* display initialization */
  /* display is already initialized by cubemx-generated code */

  /* display buffer initialization */
  lv_disp_draw_buf_init (&disp_buf,
                         (void*) LVGL_BUFFER_1_ADDR_AT_SDRAM,
                         (void*) LVGL_BUFFER_2_ADDR_AT_SDRAM,
                         MY_DISP_HOR_RES * MY_DISP_VER_RES);

  /* register the display in LVGL */
  lv_disp_drv_init(&disp_drv);

  /* set the resolution of the display */
  disp_drv.hor_res = MY_DISP_HOR_RES;
  disp_drv.ver_res = MY_DISP_VER_RES;

  /* set callback for display driver */
  disp_drv.flush_cb = disp_flush;
  disp_drv.full_refresh = 1;
  disp_drv.direct_mode = 0;

  /* interrupt callback for DMA2D transfer */
  hdma2d.XferCpltCallback = disp_flush_complete;

  /* set a display buffer */
  disp_drv.draw_buf = &disp_buf;

  /* finally register the driver */
  lv_disp_drv_register(&disp_drv);
}

//void lvgl_test(void)
//{
//  lv_color_t buf[BUF_W * BUF_H];
//  lv_color_t * buf_p = buf;
//  uint16_t x, y;
//  for(y = 0; y < BUF_H; y++) {
//      lv_color_t c = lv_color_mix(LV_COLOR_BLUE, LV_COLOR_RED, (y * 255) / BUF_H);
//      for(x = 0; x < BUF_W; x++){
//          (*buf_p) =  c;
//          buf_p++;
//      }
//  }
//
//  lv_area_t a;
//  a.x1 = 10;
//  a.y1 = 40;
//  a.x2 = a.x1 + BUF_W - 1;
//  a.y2 = a.y1 + BUF_H - 1;
//  disp_flush(NULL, &a, buf);
//}
/**********************
 *   STATIC FUNCTIONS
 **********************/

static void disp_flush (lv_disp_drv_t *drv, const lv_area_t *area, lv_color_t *color_p)
{
  lv_coord_t width = lv_area_get_width(area);
  lv_coord_t height = lv_area_get_height(area);

//  uint8_t * color24 = (uint8_t *) color_p;
//  uint8_t * color32 = (uint8_t *) color_p;
//
//  uint32_t size = lv_area_get_size(area);
//  for(int i; i < size; i++) {
//    color24[0] = color32[0];
//    color24[1] = color32[1];
//    color24[2] = color32[2];
//    color24+=3;
//    color32+=4;
//  }

  DMA2D->CR = 0x0U << DMA2D_CR_MODE_Pos;
  DMA2D->FGPFCCR = DMA2D_OUTPUT_ARGB8888;
  DMA2D->FGMAR = (uint32_t)color_p;
  DMA2D->FGOR = 0;
  DMA2D->OPFCCR = DMA2D_OUTPUT_ARGB8888;
  DMA2D->OMAR = hltdc.LayerCfg[0].FBStartAdress + 2 * (area->y1 * MY_DISP_HOR_RES + area->x1);
  DMA2D->OOR = MY_DISP_HOR_RES - width;
  DMA2D->NLR = (width << DMA2D_NLR_PL_Pos) | (height << DMA2D_NLR_NL_Pos);
  DMA2D->IFCR = 0x3FU;
  DMA2D->CR |= DMA2D_CR_TCIE;
  DMA2D->CR |= DMA2D_CR_START;
}

static void disp_flush_complete (DMA2D_HandleTypeDef *hdma2d)
{
  lv_disp_flush_ready(&disp_drv);
}
