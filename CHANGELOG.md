# Registro de Cambios (Changelog) - Proyecto Marlin Creality v4.2.7 + CXSW043 + CR Touch

## [2026-10-18] - Sincronización de Driver DWIN IA_CREALITY y Descongelamiento de Pantalla CXSW043 (Solicitud #16)

### Diagnóstico de la Falla:
- **Síntoma:** Al encender la impresora, la pantalla se mostraba verticalmente pero se quedaba congelada en la pantalla de inicio (`00_StartingTM3D.bmp`) con el logo de "Tiny Machines 3D / Creality" y la barra de progreso vacía (al 0%).
- **Causa Raíz:** El paquete de pantalla `CR6E3_PortraitTouch_TM3D` flasheado en la pantalla pertenece a la arquitectura InsanityAutomation/TinyMachines3D. Este paquete espera comandos al registro de progreso `StartIcon` (VP `0x1000`) y salto de página a través del registro `0x0084`. En contraste, el firmware Marlin anterior ejecutaba el driver clásico `DGUS_LCD_UI_ORIGIN`, el cual enviaba una orden de cambio a la pantalla número 10 (inexistente en este paquete), haciendo que el controlador DWIN ignorara la orden y permaneciera congelado en la pantalla 0.

### Cambios Implementados:
1. **Integración del Driver `DGUS_LCD_UI_IA_CREALITY`:**
   - Incorporación de los módulos [`Marlin/src/lcd/extui/ia_creality/`](Marlin/src/lcd/extui/ia_creality/):
     - `creality_extui.cpp` y `creality_extui.h`: Manejo de protocolo nativo DWIN, arranque con actualización progresiva de la barra de inicio (`startprogress`), intercambio de páginas de menús, temperaturas, coordenadas y estado de impresión.
     - `FileNavigator.cpp` y `FileNavigator.h`: Explorador y renderizado de carpetas/archivos G-code en la tarjeta SD para la interfaz táctil.
2. **Configuración de Marlin y PlatformIO:**
   - [`ini/features.ini`](ini/features.ini): Añadido filtro de compilación `DGUS_LCD_UI_IA_CREALITY = build_src_filter=+<src/lcd/extui/ia_creality>`.
   - [`Marlin/src/inc/Conditionals_LCD.h`](Marlin/src/inc/Conditionals_LCD.h) y [`Marlin/src/inc/SanityCheck.h`](Marlin/src/inc/SanityCheck.h): Activación de `HAS_DGUS_LCD` y compatibilidad con `EXTENSIBLE_UI`.
   - [`Marlin/Configuration.h`](Marlin/Configuration.h) y [`Marlin/Configuration_adv.h`](Marlin/Configuration_adv.h):
     - Selección de `DGUS_LCD_UI_IA_CREALITY` en lugar de `DGUS_LCD_UI_ORIGIN`.
     - Habilitación de `NOZZLE_PARK_FEATURE`, `LCD_BED_TRAMMING` y `ADVANCED_PAUSE_FEATURE` requeridos por la interfaz táctil Creality.
3. **Adaptación a API Marlin 2.1.2.9:**
   - Actualización de llamadas obsoletas (`getMeshValid()` a `getLevelingIsValid()`).
   - Soporte dinámico para Classic Jerk / Junction Deviation.
4. **Compilación y Entrega:**
   - Compilación exitosa con PlatformIO (`genericSTM32F103RE`): RAM 10.0%, Flash 25.9%.
   - Nuevo binario listo en [`build/creality_v427/firmware-20261018-174216.bin`](build/creality_v427/firmware-20261018-174216.bin) y [`build/creality_v427/firmware.bin`](build/creality_v427/firmware.bin).

---

## [2026-10-18] - Corrección de Orientación Portrait 272x480 y Error MINTEMP (Solicitud #15)
- Diagnóstico de montaje vertical en Ender-3 (resolución nativa 272x480) y error `STOPPED. Please Reset` por ausencia de termistores durante pruebas de banco.
- Despliegue de assets verticales en [`build/display_CXSW043_portrait/DWIN_SET/`](build/display_CXSW043_portrait/DWIN_SET/) con `T5LCFG_272480.CFG`.
- Configuración de `CONFIG_EMULATE_THERMISTORS` y `CONFIG_MINTEMP 0` en [`PRINTER_CONFIG.h`](PRINTER_CONFIG.h).

---

## [2026-10-17] - Soporte Inicial Placa Creality v4.2.7 + CR Touch + DGUS (Solicitudes #1 - #14)
- Configuración de controladores silenciosos TMC2208 Standalone en X, Y, Z, E0.
- Integración de sensor CR Touch en puerto de 5 pines (PB1/PB0) con `Z_SAFE_HOMING`, babystepping y prueba de repetibilidad `M48`.
- Creación de scripts de prueba [`build/01_test_cr_touch_manual.gcode`](build/01_test_cr_touch_manual.gcode) y [`build/test_cr_touch.gcode`](build/test_cr_touch.gcode).
- Creación de [`PRINTER_CONFIG.h`](PRINTER_CONFIG.h) para configuración centralizada y scripts de compilación de 1 clic [`build.ps1`](build.ps1) y [`build.bat`](build.bat).
