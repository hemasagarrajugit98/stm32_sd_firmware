/*
 * File: dma_spi.c
 * Description: Implements SPI communication using DMA on STM32.
 */

 #include "dma_spi.h"

 // Initialize DMA for SPI communication
 void DMA_SPI_Init(SPI_HandleTypeDef *hspi) {
     __HAL_RCC_DMA2_CLK_ENABLE();
     
     // Configure DMA for SPI TX
     static DMA_HandleTypeDef hdma_tx;
     hdma_tx.Instance = DMA2_Stream3;
     hdma_tx.Init.Channel = DMA_CHANNEL_3;
     hdma_tx.Init.Direction = DMA_MEMORY_TO_PERIPH;
     hdma_tx.Init.PeriphInc = DMA_PINC_DISABLE;
     hdma_tx.Init.MemInc = DMA_MINC_ENABLE;
     hdma_tx.Init.PeriphDataAlignment = DMA_PDATAALIGN_BYTE;
     hdma_tx.Init.MemDataAlignment = DMA_MDATAALIGN_BYTE;
     hdma_tx.Init.Mode = DMA_NORMAL;
     hdma_tx.Init.Priority = DMA_PRIORITY_HIGH;
     hdma_tx.Init.FIFOMode = DMA_FIFOMODE_DISABLE;
     HAL_DMA_Init(&hdma_tx);
     __HAL_LINKDMA(hspi, hdmatx, hdma_tx);
 }
 
 // Transmit data via SPI using DMA
 HAL_StatusTypeDef DMA_SPI_Transmit(SPI_HandleTypeDef *hspi, uint8_t *pData, uint16_t Size) {
     return HAL_SPI_Transmit_DMA(hspi, pData, Size);
 }
 
 // Receive data via SPI using DMA
 HAL_StatusTypeDef DMA_SPI_Receive(SPI_HandleTypeDef *hspi, uint8_t *pData, uint16_t Size) {
     return HAL_SPI_Receive_DMA(hspi, pData, Size);
 }
 