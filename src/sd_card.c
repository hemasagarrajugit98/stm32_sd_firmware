/*
 * File: sd_card.c
 * Description: SPI-based SD/MMC Card Driver for STM32
 *              Implements low-level SPI communication with SD/MMC cards.
 */

 #include "sd_card.h"
 #include "stm32f4xx_hal.h"
 
 #define SD_CMD0  0x40  // GO_IDLE_STATE
 #define SD_CMD8  0x48  // SEND_IF_COND
 #define SD_CMD55 0x77  // APP_CMD
 #define SD_ACMD41 0x69 // SD_SEND_OP_COND
 
 SPI_HandleTypeDef hspi1;
 
 // Initialize SPI for SD card communication
 int SD_Card_Init(void) {
     uint8_t response;
     uint32_t retry = 0;
     
     // Configure SPI parameters
     hspi1.Instance = SPI1;
     hspi1.Init.Mode = SPI_MODE_MASTER;
     hspi1.Init.Direction = SPI_DIRECTION_2LINES;
     hspi1.Init.DataSize = SPI_DATASIZE_8BIT;
     hspi1.Init.CLKPolarity = SPI_POLARITY_HIGH;
     hspi1.Init.CLKPhase = SPI_PHASE_2EDGE;
     hspi1.Init.NSS = SPI_NSS_SOFT;
     hspi1.Init.BaudRatePrescaler = SPI_BAUDRATEPRESCALER_8;
     hspi1.Init.FirstBit = SPI_FIRSTBIT_MSB;
     hspi1.Init.TIMode = SPI_TIMODE_DISABLE;
     hspi1.Init.CRCCalculation = SPI_CRCCALCULATION_DISABLE;
     hspi1.Init.CRCPolynomial = 10;
     
     if (HAL_SPI_Init(&hspi1) != HAL_OK) {
         return -1;
     }
     
     // Send CMD0 to reset the SD card
     response = SD_SendCommand(SD_CMD0, 0);
     while (response != 0x01 && retry < 1000) {
         response = SD_SendCommand(SD_CMD0, 0);
         retry++;
     }
     if (retry >= 1000) return -2; // Timeout error
     
     return 0; // Success
 }
 
 // Send SPI command to SD card
 uint8_t SD_SendCommand(uint8_t cmd, uint32_t arg) {
     uint8_t frame[6];
     frame[0] = cmd;
     frame[1] = (uint8_t)(arg >> 24);
     frame[2] = (uint8_t)(arg >> 16);
     frame[3] = (uint8_t)(arg >> 8);
     frame[4] = (uint8_t)(arg);
     frame[5] = 0x95; // CRC for CMD0
     
     HAL_SPI_Transmit(&hspi1, frame, 6, HAL_MAX_DELAY);
     uint8_t response;
     HAL_SPI_Receive(&hspi1, &response, 1, HAL_MAX_DELAY);
     return response;
 }
 