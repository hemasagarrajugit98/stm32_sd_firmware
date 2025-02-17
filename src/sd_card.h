/*
 * File: sd_card.h
 * Description: Header file for SD/MMC SPI-based driver for STM32.
 *              Declares functions and constants for SD card communication.
 */

 #ifndef SD_CARD_H
 #define SD_CARD_H
 
 #include "stm32f4xx_hal.h"
 
 // SD/MMC Card Commands
 #define SD_CMD0  0x40  // GO_IDLE_STATE
 #define SD_CMD8  0x48  // SEND_IF_COND
 #define SD_CMD55 0x77  // APP_CMD
 #define SD_ACMD41 0x69 // SD_SEND_OP_COND
 
 // Function Prototypes
 int SD_Card_Init(void);
 uint8_t SD_SendCommand(uint8_t cmd, uint32_t arg);
 
 #endif /* SD_CARD_H */
 