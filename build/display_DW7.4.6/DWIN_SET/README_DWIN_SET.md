# Conjunto de Archivos DWIN_SET para DW7.4.6

La carpeta `DWIN_SET` contiene la interfaz gráfica, fuentes de texto, tablas de iconos táctiles y parámetros del sistema operativo DWIN (DGUS II / T5L) correspondientes a la versión **DW7.4.6** (desarrollada por Insanity Automation / Tiny Machines 3D).

---

## 1. Requisitos para la Tarjeta MicroSD de la Pantalla

Para que el chip DWIN reconozca y flashee el paquete `DWIN_SET`, la tarjeta MicroSD debe cumplir estrictamente estas condiciones:

- **Capacidad**: MicroSD de **8 GB** o máximo **16 GB** (las tarjetas de 32GB o superiores a menudo no son leídas por el bootloader del procesador DWIN T5L/T5UID).
- **Sistema de Archivos**: **FAT32**.
- **Tamaño de Asignación (Clúster)**: **4096 bytes** (4KB). *(Esencial: si se formatea con otro tamaño de bloque, la pantalla mostrará error o pantalla negra/azul sin actualizar).*

### Comando de Formateo en Windows (PowerShell / CMD):
```powershell
format D: /fs:fat32 /q /a:4096
```
*(Reemplaza `D:` por la letra real de tu unidad MicroSD)*.

---

## 2. Estructura de Archivos en la MicroSD

En la raíz de la tarjeta MicroSD debe quedar exactamente así:

```
SD_CARD (Raíz)
└── DWIN_SET/
    ├── 0_ext_dw7.4.6.bin (o archivo de configuración del sistema)
    ├── 13_Touch_Area.bin
    ├── 14_Variable_Icon.bin
    ├── T5UID1.CFG / T5L_CONFIG.CFG
    └── *.ICO / *.FON (fuentes e iconos de la interfaz)
```

> [!IMPORTANT]
> La carpeta **debe llamarse exactamente `DWIN_SET`** (en mayúsculas) y estar en la raíz de la memoria, sin carpetas intermedias.

---

## 3. Proceso de Flasheo de la Pantalla

1. Retira la cubierta posterior de la pantalla para acceder a la ranura MicroSD interna (incorporada en la propia placa del display, no la ranura de la impresora).
2. Con la impresora **apagada**, inserta la tarjeta MicroSD con la carpeta `DWIN_SET`.
3. Enciende la impresora (o alimenta la pantalla con 5V).
4. La pantalla cambiará a color azul y mostrará una secuencia de carga de archivos (`SD Card Process...`, carga de fuentes, iconos y configuración).
5. Cuando la pantalla cambie a color naranja o indique `SUCCESS! / END`, el proceso habrá finalizado (suele tardar entre 10 y 30 segundos).
6. Apaga la impresora, extrae la MicroSD de la pantalla y vuelve a armar la carcasa.
