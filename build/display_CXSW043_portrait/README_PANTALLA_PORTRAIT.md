# Firmware de Pantalla CXSW043 en Orientación Vertical (Portrait 272x480)

Este paquete contiene los archivos de firmware y assets gráficos específicamente compilados para la pantalla táctil **Creality CXSW043** montada de forma vertical en impresoras **Ender-3** y **CR-6**.

## ¿Por qué se veía "de lado"?
El paquete anterior correspondía a una pantalla en orientación horizontal (*Landscape 480x272*). Al montarse la pantalla en el soporte vertical de la Ender-3, la imagen aparecía girada 90°.
Este paquete `display_CXSW043_portrait/DWIN_SET/` contiene el archivo de configuración `T5LCFG_272480.CFG` (272x480) y todos los bitmaps e íconos en orientación vertical nativa.

## Instrucciones de Instalación en la Pantalla

1. **Formateo de la MicroSD:**
   - Usa una tarjeta MicroSD de 8 GB o 16 GB (las de 32 GB o más a menudo no son leídas por el chip DWIN).
   - Formatea la tarjeta en **FAT32** con un tamaño de unidad de asignación de **4096 bytes (4 KB)**.

2. **Copiar los archivos:**
   - Copia la carpeta **`DWIN_SET`** ubicada en esta carpeta directamente a la **raíz** de la tarjeta MicroSD.
   - En la raíz de la tarjeta debe quedar únicamente la carpeta `DWIN_SET` conteniendo los archivos (como `T5LCFG_272480.CFG`, `00_StartingTM3D.bmp`, etc.).

3. **Flasheo de la Pantalla:**
   - Apaga la impresora.
   - Retira la tapa posterior del soporte de la pantalla para acceder a la ranura MicroSD dedicada del módulo LCD.
   - Inserta la tarjeta MicroSD en la ranura de la pantalla.
   - Enciende la impresora.
   - La pantalla se encenderá en color azul, cargará los archivos y finalmente pasará a color anaranjado mostrando el número de archivos cargados y la palabra **"END"**.
   - Apaga la impresora, extrae la tarjeta MicroSD de la pantalla y vuelve a colocar la tapa.
   - Al encender, la interfaz se mostrará correctamente orientada en vertical.
