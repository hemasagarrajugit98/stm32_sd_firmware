# 📌 Installation Guide for STM32 SD/MMC Firmware Project

## **1️⃣ System Requirements**
### **🖥️ Hardware:**
- STM32F407G-DISC1 Board
- SPI-based SD/MMC Card Module
- MicroSD Card (Class 10 or higher, FAT32 formatted)
- USB-to-UART Debug Adapter (CP2102 or FTDI FT232RL)
- ST-Link V2 Debugger (Optional, if not using onboard ST-Link)
- Logic Analyzer (Optional for SPI debugging)

### **💾 Software & Tools:**
- **VSCode** (Recommended for Development)
- **CMake** (`brew install cmake` on macOS)
- **GCC ARM Toolchain** (`brew install arm-none-eabi-gcc`)
- **STM32CubeMX & STM32CubeIDE** ([Download](https://www.st.com/en/development-tools/stm32cubemx.html))
- **OpenOCD for Debugging** (`brew install openocd`)
- **STM32CubeProgrammer** ([Download](https://www.st.com/en/development-tools/stm32cubeprog.html))

## **2️⃣ Cloning the Repository**
```bash
git clone https://github.com/yourusername/stm32_sd_firmware.git
cd stm32_sd_firmware
```

## **3️⃣ Building the Project using CMake**
```bash
mkdir build && cd build
cmake ..
make
```

## **4️⃣ Flashing Firmware to STM32**
```bash
openocd -f interface/stlink.cfg -f target/stm32f4x.cfg -c "program build/stm32_sd_firmware.elf verify reset exit"
```

## **5️⃣ Running and Debugging**
To connect to the STM32 debug console:
```bash
screen /dev/tty.usbserial-XXXX 115200
```
(Replace `XXXX` with your USB-UART adapter identifier.)

## **6️⃣ Verifying SD/MMC File Operations**
After flashing, verify file system operations:
```c
FatFS_WriteFile("test.txt", "Hello World!");
FatFS_ReadFile("test.txt", buffer, sizeof(buffer));
printf("File Content: %s", buffer);
```

## **📌 Next Steps:**
- Run unit tests for SD/MMC functionality
- Optimize power consumption features
- Implement additional file operations

For more details, refer to the [Hardware Setup Guide](hardware_setup.md).
