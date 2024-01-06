SET PATH=C:\Keil_v5\ARM\ARMCLANG\Bin;C:\Program Files\STMicroelectronics\STM32Cube\STM32CubeMX\;C:\Program Files\Common Files\Oracle\Java\javapath;C:\Program Files (x86)\Common Files\Oracle\Java\javapath;C:\Users\quanv\AppData\Local\Programs\Python\Python312;C:\Users\quanv\AppData\Local\Programs\Python\Python312\Scripts;C:\Windows\system32;C:\Windows;C:\Windows\System32\Wbem;C:\Windows\System32\WindowsPowerShell\v1.0\;C:\Windows\System32\OpenSSH\;C:\Program Files (x86)\NVIDIA Corporation\PhysX\Common;C:\Program Files\NVIDIA Corporation\NVIDIA NvDLISR;C:\WINDOWS\system32;C:\WINDOWS;C:\WINDOWS\System32\Wbem;C:\WINDOWS\System32\WindowsPowerShell\v1.0\;C:\WINDOWS\System32\OpenSSH\;C:\Program Files (x86)\STMicroelectronics\STM32 ST-LINK Utility\ST-LINK Utility;C:\Users\quanv\AppData\Local\Programs\Python\Launcher;C:\Program Files\Cloudflare\Cloudflare WARP\;C:\Program Files\Git\cmd;C:\Program Files\Java\jdk-21\bin;C:\Program Files\MATLAB\R2017b\runtime\win64;C:\Program Files\MATLAB\R2017b\bin;C:\Program Files (x86)\GnuWin32\bin;C:\Users\quanv\AppData\Local\Programs\Python\Launcher\;C:\Users\quanv\AppData\Local\Microsoft\WindowsApps;C:\Users\quanv\AppData\Local\Programs\Microsoft VS Code\bin;C:\MinGW\bin;C:\Users\quanv\AppData\Local\GitHubDesktop\bin;C:\Program Files\STMicroelectronics\STM32Cube\STM32CubeMX\.\jre\\bin
SET CPU_TYPE=STM32F103C8
SET CPU_VENDOR=STMicroelectronics
SET UV2_TARGET=HAL_SPI
SET CPU_CLOCK=0x007A1200
"C:\Keil_v5\ARM\ARMCLANG\Bin\ArmClang.exe" @"hal_spi\startup_stm32f103xb._ac"
"C:\Keil_v5\ARM\ARMCLANG\Bin\ArmClang.exe" @"hal_spi\main.__i"
"C:\Keil_v5\ARM\ARMCLANG\Bin\ArmClang.exe" @"hal_spi\stm32f1xx_it.__i"
"C:\Keil_v5\ARM\ARMCLANG\Bin\ArmClang.exe" @"hal_spi\stm32f1xx_hal_msp.__i"
"C:\Keil_v5\ARM\ARMCLANG\Bin\ArmClang.exe" @"hal_spi\stm32f1xx_hal_gpio_ex.__i"
"C:\Keil_v5\ARM\ARMCLANG\Bin\ArmClang.exe" @"hal_spi\stm32f1xx_hal_spi.__i"
"C:\Keil_v5\ARM\ARMCLANG\Bin\ArmClang.exe" @"hal_spi\stm32f1xx_hal.__i"
"C:\Keil_v5\ARM\ARMCLANG\Bin\ArmClang.exe" @"hal_spi\stm32f1xx_hal_rcc.__i"
"C:\Keil_v5\ARM\ARMCLANG\Bin\ArmClang.exe" @"hal_spi\stm32f1xx_hal_rcc_ex.__i"
"C:\Keil_v5\ARM\ARMCLANG\Bin\ArmClang.exe" @"hal_spi\stm32f1xx_hal_gpio.__i"
"C:\Keil_v5\ARM\ARMCLANG\Bin\ArmClang.exe" @"hal_spi\stm32f1xx_hal_dma.__i"
"C:\Keil_v5\ARM\ARMCLANG\Bin\ArmClang.exe" @"hal_spi\stm32f1xx_hal_cortex.__i"
"C:\Keil_v5\ARM\ARMCLANG\Bin\ArmClang.exe" @"hal_spi\stm32f1xx_hal_pwr.__i"
"C:\Keil_v5\ARM\ARMCLANG\Bin\ArmClang.exe" @"hal_spi\stm32f1xx_hal_flash.__i"
"C:\Keil_v5\ARM\ARMCLANG\Bin\ArmClang.exe" @"hal_spi\stm32f1xx_hal_flash_ex.__i"
"C:\Keil_v5\ARM\ARMCLANG\Bin\ArmClang.exe" @"hal_spi\stm32f1xx_hal_exti.__i"
"C:\Keil_v5\ARM\ARMCLANG\Bin\ArmClang.exe" @"hal_spi\stm32f1xx_hal_tim.__i"
"C:\Keil_v5\ARM\ARMCLANG\Bin\ArmClang.exe" @"hal_spi\stm32f1xx_hal_tim_ex.__i"
"C:\Keil_v5\ARM\ARMCLANG\Bin\ArmClang.exe" @"hal_spi\system_stm32f1xx.__i"
"C:\Keil_v5\ARM\ARMCLANG\Bin\ArmLink" --Via "HAL_SPI\HAL_SPI.lnp"
"C:\Keil_v5\ARM\ARMCLANG\Bin\fromelf.exe" "HAL_SPI\HAL_SPI.axf" --i32combined --output "HAL_SPI\HAL_SPI.hex"
