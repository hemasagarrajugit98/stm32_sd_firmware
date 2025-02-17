# 📌 Development Workflow for STM32 SD/MMC Firmware Project

## **1️⃣ Project Setup**
### **Clone Repository and Set Up Development Environment**
```bash
git clone https://github.com/yourusername/stm32_sd_firmware.git
cd stm32_sd_firmware
```

### **Configure CMake and Build System**
```bash
mkdir build && cd build
cmake ..
make
```

## **2️⃣ Development Process**
### **1. Implement Features**
- Develop firmware modules in `src/`
- Modify hardware configurations in `inc/`
- Use `docs/` for documentation updates

### **2. Code Compilation**
Run the following to compile the firmware:
```bash
make clean
make
```

### **3. Flashing Firmware to STM32**
```bash
openocd -f interface/stlink.cfg -f target/stm32f4x.cfg -c "program build/stm32_sd_firmware.elf verify reset exit"
```

### **4. Debugging and Testing**
Use `screen` or serial monitor for debugging:
```bash
screen /dev/tty.usbserial-XXXX 115200
```
(Replace `XXXX` with your USB-UART adapter identifier.)

### **5. Commit and Push Changes**
```bash
git add .
git commit -m "Implemented new feature"
git push origin main
```

## **3️⃣ Collaboration and Issue Tracking**
- Use GitHub Issues for bug tracking.
- Create branches for new feature development.
- Submit pull requests for code reviews.

## **📌 Next Steps:**
- Optimize SD/MMC read/write operations.
- Implement error handling and power management.
- Document API functions and usage examples.
