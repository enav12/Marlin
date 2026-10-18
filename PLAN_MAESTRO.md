# Plan Maestro: Marlin 2.1.2.9 + Creality v4.2.7 + Pantalla CXSW043 + CR Touch

> [!NOTE]
> Este documento es el **Plan Maestro del Proyecto**. Ha sido reiniciado tras la resolución e implementación exitosa de las solicitudes anteriores (Fases 1 a 8), las cuales han sido consolidadas y archivadas en el [`CHANGELOG.md`](CHANGELOG.md).

> [!IMPORTANT]
> **Regla Operativa del Proyecto (AGENTS.md)**:
> 1. Si el usuario formula una consulta con signo de interrogación (`?` o `¿`), **NO se debe generar ni modificar el plan**, solo contestar directamente por pantalla/chat.
> 2. Si el usuario realiza una solicitud de implementación o cambio técnico (sin signo de interrogación), se registra en este plan y se ejecuta.
> 3. Al implementar y validar cada solicitud, se marca como resuelta, se genera el registro en [`CHANGELOG.md`](CHANGELOG.md) y se reinicia el plan desde cero.

---

## 1. Estado Actual del Sistema

- **Placa Base**: Creality v4.2.7 (STM32F103RET6) con controladores silenciosos TMC2208 Standalone.
- **Sensor CR Touch**: Configurado en puerto dedicado de 5 pines (PB1/PB0) con `Z_SAFE_HOMING`, nivelación bilineal y babystepping.
- **Pantalla Táctil**: Creality CXSW043 (DWIN T5L 272x480 Portrait) con driver nativo `DGUS_LCD_UI_IA_CREALITY` sincronizado en UART3 (EXP1).
- **Control Centralizado**: Todos los parámetros gestionados desde [`PRINTER_CONFIG.h`](PRINTER_CONFIG.h).
- **Directorio de Binarios**: Paquetes listos en [`build/`](build/).
  - Binario actual compilado: [`build/creality_v427/firmware-20261018-174216.bin`](build/creality_v427/firmware-20261018-174216.bin).
  - Paquete de pantalla portrait: [`build/display_CXSW043_portrait/DWIN_SET/`](build/display_CXSW043_portrait/DWIN_SET/).
- **Compilador**: Scripts de 1 clic [`build.ps1`](build.ps1) y [`build.bat`](build.bat).

---

## 2. Registro de Nuevas Solicitudes

| # | Solicitud | Alcance / Tareas | Estado |
| :-: | :--- | :--- | :-: |
| - | *En espera de nueva solicitud...* | *Sin tareas pendientes* | 🟢 **Listo** |

---

## 3. Próximos Pasos Disponibles
1. El usuario flashea el nuevo binario [`firmware-20261018-174216.bin`](build/creality_v427/firmware-20261018-174216.bin) en la placa base para descongelar la pantalla de inicio y acceder al menú principal.
2. Ejecutar la prueba interactiva del sensor CR Touch con [`build/01_test_cr_touch_manual.gcode`](build/01_test_cr_touch_manual.gcode).
