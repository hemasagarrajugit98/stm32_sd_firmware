/*
 * File: fatfs_config.c
 * Description: Implements FAT32/exFAT file system support using FatFs library
 *              for STM32 SD/MMC card.
 */

 #include "fatfs_config.h"
 #include "ff.h"
 
 static FATFS fs;   // File system object
 static FIL file;   // File object
 
 // Initialize FatFs file system
 int FatFS_Init(void) {
     FRESULT res = f_mount(&fs, "", 1);
     return (res == FR_OK) ? 0 : -1;
 }
 
 // Mount SD card file system
 int FatFS_Mount(void) {
     return FatFS_Init();
 }
 
 // Write data to a file
 int FatFS_WriteFile(const char *filename, const char *data) {
     UINT bw;
     FRESULT res = f_open(&file, filename, FA_WRITE | FA_CREATE_ALWAYS);
     if (res != FR_OK) return -1;
     res = f_write(&file, data, strlen(data), &bw);
     f_close(&file);
     return (res == FR_OK) ? 0 : -1;
 }
 
 // Read data from a file
 int FatFS_ReadFile(const char *filename, char *buffer, uint32_t bufsize) {
     UINT br;
     FRESULT res = f_open(&file, filename, FA_READ);
     if (res != FR_OK) return -1;
     res = f_read(&file, buffer, bufsize - 1, &br);
     buffer[br] = '\0';  // Null terminate the string
     f_close(&file);
     return (res == FR_OK) ? 0 : -1;
 }
 
 // Delete a file
 int FatFS_DeleteFile(const char *filename) {
     FRESULT res = f_unlink(filename);
     return (res == FR_OK) ? 0 : -1;
 }
 