# 📌 Hardware Setup Guide for STM32 SD/MMC Firmware Project

## **1️⃣ Components Required**
- **STM32F407G-DISC1** *(Microcontroller Board)*
- **MicroSD Card Module** *(SPI-based)*
- **MicroSD Card** *(Class 10, formatted as FAT32)*
- **USB-to-UART Debug Adapter** *(CP2102 or FT232RL)*
- **ST-Link V2 Debugger** *(Optional, for flashing firmware)*
- **Logic Analyzer** *(Optional, for debugging SPI communication)*

## **2️⃣ Wiring Diagram**
| SD Card Module | STM32F407G-DISC1 |
|---------------|----------------|
| **VCC** (3.3V) | 3.3V |
| **GND** | GND |
| **MISO** | SPI1_MISO (PA6) |
| **MOSI** | SPI1_MOSI (PA7) |
| **SCK** | SPI1_SCK (PA5) |
| **CS** | GPIO (PA4) |

## **3️⃣ Connection Steps**
1. **Connect the MicroSD Card Module** to the STM32 board as per the wiring diagram.
2. **Connect the USB-to-UART Adapter** to STM32 for serial debugging:
   - TX → RX (PA10)
   - RX → TX (PA9)
   - GND → GND
3. **Connect ST-Link V2** (if needed for flashing firmware):
   - SWDIO → SWDIO (PA13)
   - SWCLK → SWCLK (PA14)
   - GND → GND

## **4️⃣ Powering the Setup**
- **Option 1:** Directly power via USB (5V) from the PC.
- **Option 2:** Use an external power supply (3.3V recommended for SD module stability).

## **5️⃣ Checking the Setup**
Run the following command to check if STM32 is detected:
```bash
openocd -f interface/stlink.cfg -f target/stm32f4x.cfg
```
Expected output should detect STM32F407.

For further debugging, use a **logic analyzer** to check SPI signal integrity.

## **📌 Next Steps:**
- Build and flash the firmware following the [Installation Guide](installation_guide.md)
- Test SD card read/write operations in STM32 firmware.
- Optimize power consumption settings for SD module.
