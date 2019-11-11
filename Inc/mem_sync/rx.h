#ifndef __MEM_SYNC_RX_H
#define __MEM_SYNC_RX_H

#include "stm32f4xx_hal.h"
#include "taskmanage.h"

// SPI only!!!

// variable BEGIN

static uint8_t signal[2] = {0b01100110, 0b01010100};

// variable END

// typedef BEGIN

typedef enum {
  FREE = 0,
  READY,
  START,
  BUSY,
  FINISH
} RX_stateTypedef;

typedef struct {
  // SPI handle
  SPI_HandleTypeDef* p_hspi;
  // DC Pin GPIO
  GPIO_TypeDef *GPIOx;
  uint16_t GPIO_Pin;
  uint8_t* dataAddress;
  uint32_t size;
  uint8_t RX_buffer;
  uint8_t DC_buffer;
  RX_stateTypedef state;
} memSync_RX_taskTypedef;

// typedef END

// functions BEGIN

void memSync_RX_taskTypedef_Init(memSync_RX_taskTypedef* memSync_RX_task,
    SPI_HandleTypeDef* p_hspi,
    GPIO_TypeDef *GPIOx,
    uint16_t GPIO_Pin,
    uint8_t* dataAddress,
    uint32_t size);

void memSync_RX_update(memSync_RX_taskTypedef* memync_RX_task);

// functions END

#endif