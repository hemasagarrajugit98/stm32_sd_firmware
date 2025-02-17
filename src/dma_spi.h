/*
 * File: dma_spi.h
 * Description: Header file for SPI communication using DMA on STM32.
 */

 #ifndef DMA_SPI_H
 #define DMA_SPI_H
 
 #include "stm32f4xx_hal.h"
 
 // Function Prototypes
 void DMA_SPI_Init(SPI_HandleTypeDef *hspi);
 HAL_StatusTypeDef DMA_SPI_Transmit(SPI_HandleTypeDef *hspi, uint8_t *pData, uint16_t Size);
 HAL_StatusTypeDef DMA_SPI_Receive(SPI_HandleTypeDef *hspi, uint8_t *pData, uint16_t Size);
 
 #endif /* DMA_SPI_H */
 