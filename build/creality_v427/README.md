# Instalador de Firmware: Placa Creality v4.2.7

Esta carpeta contiene las instrucciones y el destino del archivo binario (`.bin`) compilado desde Marlin listo para flashear en la placa **Creality v4.2.7**.

---

## 1. Archivo Binario a Instalar

Al compilar Marlin mediante PlatformIO (`default_envs = STM32F103RE_creality`), el binario generado se ubicará en:
- Ruta de compilación interna: `.pio/build/STM32F103RE_creality/firmware.bin`
- Copia para instalación: Este directorio (`build/creality_v427/firmware_[fecha].bin`)

---

## 2. Instrucciones de Instalación en la Placa v4.2.7

1. **Tarjeta MicroSD**: Formatear en **FAT32** con tamaño de asignación de **4096 bytes** (tarjetas de 8GB o 16GB recomendadas).
2. **Nombre del archivo**: Copiar el archivo `.bin` en la raíz de la MicroSD.
   > [!IMPORTANT]
   > El bootloader de Creality requiere que el nombre sea diferente al último instalado (por ejemplo: `firmware_20261017.bin` o `Marlin427_01.bin`).
3. **Instalación**:
   - Con la impresora apagada, insertar la MicroSD en la ranura de la placa base.
   - Encender la impresora. La pantalla permanecerá en espera unos 10-15 segundos mientras se programa el chip STM32F103.
   - Al finalizar, la máquina iniciará con el nuevo firmware Marlin.
