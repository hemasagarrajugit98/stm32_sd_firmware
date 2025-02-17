/*
 * File: fatfs_config.h
 * Description: Header file for configuring FAT32/exFAT file system support
 *              for SD/MMC card using FatFs library on STM32.
 */

 #ifndef FATFS_CONFIG_H
 #define FATFS_CONFIG_H
 
 #include "stm32f4xx_hal.h"
 #include "ff.h"  // FatFs library
 
 // Function Prototypes
 int FatFS_Init(void);
 int FatFS_Mount(void);
 int FatFS_WriteFile(const char *filename, const char *data);
 int FatFS_ReadFile(const char *filename, char *buffer, uint32_t bufsize);
 int FatFS_DeleteFile(const char *filename);
 
 #endif /* FATFS_CONFIG_H */
 