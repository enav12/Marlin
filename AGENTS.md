# Reglas del Proyecto Marlin (Creality v4.2.7 + DW7.4.6 + CR Touch)

## 1. Regla de Consultas vs. Solicitudes de Implementación
* **Consultas con signo de interrogación (`?` / `¿`)**:
  - Si el usuario formula una consulta que contiene signos de interrogación, **NO se debe generar ni modificar el Plan Maestro**.
  - Se debe responder **únicamente por pantalla / chat**, respondiendo de manera clara, concisa y directa a la duda, diagnóstico o consulta técnica planteada.

* **Solicitudes de Implementación o Cambios**:
  - Si el usuario solicita una nueva funcionalidad, ajuste de configuración, compilación o cambio técnico (sin signo de interrogación), se debe mantener y actualizar el Plan Maestro Incremental ([`PLAN_MAESTRO.md`](PLAN_MAESTRO.md)) registrando la solicitud y su estado. Cuando el plan sea implementado se debe marcar como resuelto y se debe generar un nuevo log de cambios y comenzar con un nuevo plan desde cero.

## 2. Reglas de Arquitectura y Compilación
* **Configuración Centralizada**: Toda modificación de parámetros de la impresora (pasos, dimensiones, probe, pantalla) debe realizarse en [`PRINTER_CONFIG.h`](PRINTER_CONFIG.h).
* **Directorio `build/`**: Todo binario o paquete instalable (`firmware.bin`, scripts G-code de prueba, archivos `DWIN_SET`) debe alojarse en la carpeta `build/`.
* **Scripts de 1 Clic**: Usar siempre [`build.ps1`](build.ps1) o [`build.bat`](build.bat) para compilar y generar los binarios con timestamp.
