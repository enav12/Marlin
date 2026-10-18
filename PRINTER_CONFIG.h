/**
 * =============================================================================
 *                       CONFIGURACIÓN RÁPIDA DE IMPRESORA
 * =============================================================================
 * Archivo: PRINTER_CONFIG.h
 * 
 * Este archivo centraliza los parámetros principales de tu impresora para que
 * puedas modificarlos fácilmente desde un solo lugar sin tener que navegar por
 * los extensos archivos internos de Marlin (Configuration.h y Configuration_adv.h).
 * 
 * Al compilar (en VS Code / PlatformIO o mediante el script build.ps1), el
 * compilador leerá automáticamente las opciones definidas aquí.
 * =============================================================================
 */

#pragma once

// =============================================================================
// 1. INFORMACIÓN DE LA MÁQUINA Y PLACA BASE
// =============================================================================
// Nombre que se mostrará en los menús de la pantalla e información del sistema:
#define CONFIG_MACHINE_NAME             "Ender-3 4.2.7"

// Modelo de la placa electrónica (placa silenciosa Creality v4.2.7):
#define CONFIG_MOTHERBOARD              BOARD_CREALITY_V427

// Velocidad del puerto USB (115200 baudios recomendado):
#define CONFIG_SERIAL_BAUDRATE          115200


// =============================================================================
// 2. DIMENSIONES Y VOLUMEN DE IMPRESIÓN (milímetros)
// =============================================================================
#define CONFIG_BED_X                    220     // Ancho de la cama (Eje X)
#define CONFIG_BED_Y                    220     // Profundidad de la cama (Eje Y)
#define CONFIG_BED_Z                    250     // Altura máxima imprimible (Eje Z)


// =============================================================================
// 3. CONTROLADORES DE MOTOR (DRIVERS SILENCIOSOS)
// =============================================================================
// La placa 4.2.7 viene de fábrica con controladores TMC2208 en modo Standalone:
#define CONFIG_DRIVER_X                 TMC2208_STANDALONE
#define CONFIG_DRIVER_Y                 TMC2208_STANDALONE
#define CONFIG_DRIVER_Z                 TMC2208_STANDALONE
#define CONFIG_DRIVER_E0                TMC2208_STANDALONE


// =============================================================================
// 4. DIRECCIÓN DE GIRO DE LOS MOTORES (INVERSIÓN DE EJES)
// =============================================================================
// Invierte el sentido del motor si algún eje se mueve hacia el lado contrario:
#define CONFIG_INVERT_X_DIR             false
#define CONFIG_INVERT_Y_DIR             false
#define CONFIG_INVERT_Z_DIR             true    // Necesario en Creality v4.2.7 con TMC2208
#define CONFIG_INVERT_E0_DIR            false


// =============================================================================
// 5. CALIBRACIÓN DE PASOS POR MILÍMETRO (STEPS/MM)
// =============================================================================
// Pasos necesarios para desplazar 1 mm en cada eje:
#define CONFIG_STEPS_X                  80.0    // Eje X (correa GT2 / polea 16 dientes)
#define CONFIG_STEPS_Y                  80.0    // Eje Y (correa GT2 / polea 16 dientes)
#define CONFIG_STEPS_Z                  400.0   // Eje Z (varilla roscada T8x8 paso 8mm)
#define CONFIG_STEPS_E                  93.0    // Extrusor Creality stock (cambiar a ~138-140 si usas Dual Drive / BMG)


// =============================================================================
// 6. SENSOR DE AUTO-NIVELACIÓN (CR TOUCH / BLTOUCH)
// =============================================================================
// true: Activa el CR Touch conectado al puerto dedicado de 5 pines (PB1/PB0)
// false: Desactiva el CR Touch y usa el final de carrera físico de Z
#define CONFIG_ENABLE_CR_TOUCH          true

// Distancia física desde la tobera (nozzle) a la punta de la sonda (en mm).
// Valores para el soporte metálico oficial de Creality montado a la izquierda:
#define CONFIG_PROBE_OFFSET_X           -44     // 44 mm a la izquierda de la tobera
#define CONFIG_PROBE_OFFSET_Y           -10     // 10 mm al frente de la tobera
#define CONFIG_PROBE_OFFSET_Z           0.0     // Z-Offset inicial (se ajusta fino con Babystepping)

// Cantidad de puntos de palpado por eje para la malla de nivelación (3 = matriz 3x3 de 9 puntos):
#define CONFIG_PROBING_GRID_POINTS      3

// Pruebas y Diagnóstico del Sensor CR Touch:
// Habilita el comando M48 (test de repetibilidad de 10 puntos en cama) y
// el comando M43 S (prueba manual interactiva: despliega la aguja, espera la
// presión de tu mano en la punta, emite un pitido y muestra confirmación en pantalla):
#define CONFIG_ENABLE_PROBE_TEST        true


// =============================================================================
// 7. PANTALLA TÁCTIL DW7.4.6 (DWIN DGUS)
// =============================================================================
// true: Activa la interfaz gráfica táctil DW7.4.6 a través del conector EXP1
// false: Desactiva la pantalla DGUS (para pantalla LCD12864 gráfica estándar)
#define CONFIG_ENABLE_DWIN_DW746        true

// Puerto serie de hardware asignado a la pantalla (UART3 = pines PB10 y PB11 de EXP1):
#define CONFIG_LCD_SERIAL_PORT          3


// =============================================================================
// 8. TEMPERATURAS MÁXIMAS DE SEGURIDAD (°C)
// =============================================================================
// La temperatura de trabajo máxima permitida es 15°C menor que el límite configurado:
#define CONFIG_HOTEND_MAXTEMP           275     // Permite imprimir hasta 260°C (PLA, PETG, ABS, TPU)
#define CONFIG_BED_MAXTEMP              125     // Permite calentar la cama hasta 110°C


// =============================================================================
// 9. FUNCIONES AVANZADAS DE CALIBRACIÓN Y CONTROL
// =============================================================================
// Babystepping: Permite micro-ajustar en vivo la altura de la 1ª capa mientras imprime:
#define CONFIG_ENABLE_BABYSTEPPING      true

// Almacenamiento EEPROM: Permite guardar ajustes con M500 (offsets, pasos, calibración):
#define CONFIG_ENABLE_EEPROM            true

// Linear Advance v1.5: Control de presión para esquinas más nítidas y flujo uniforme:
#define CONFIG_ENABLE_LINEAR_ADVANCE    false
#define CONFIG_LIN_ADVANCE_K            0.0     // Factor K (calibrar con prueba de líneas K=0.0 a 0.2)
