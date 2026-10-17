/**
 * Guía de Parches para Marlin 2.1.2.9 con Pantalla DW7.4.6 y Placa Creality v4.2.7
 * 
 * Estas directivas se aplican a los archivos Configuration.h y Configuration_adv.h
 * para habilitar la comunicación bidireccional entre la placa v4.2.7 y la pantalla DWIN DW7.4.6.
 */

// =============================================================================
// 1. CAMBIOS EN: Marlin/Configuration.h
// =============================================================================

// Placa base Creality 4.2.7 (STM32F103)
#define MOTHERBOARD BOARD_CREALITY_V427

// Comunicación Serie Dual:
// Puerto 1: Conexión USB al computador (CH340 / USART1)
#define SERIAL_PORT 1
#define BAUDRATE 115200

// Puerto 2: Conexión USART3 en conector EXP1 hacia la pantalla DWIN (PB10 / PB11)
#define SERIAL_PORT_2 3
#define BAUDRATE_2 115200

// Interfaz Gráfica DGUS / DWIN para pantalla táctil
// Selecciona la variante compatible con el juego de iconos DW7.4.6:
#define DGUS_LCD_UI_ORIGIN
// Alternativa para interfaces recargadas:
// #define DGUS_LCD_UI_RELOADED


// =============================================================================
// 2. CAMBIOS EN: Marlin/Configuration_adv.h
// =============================================================================

#if HAS_DGUS_LCD
  // Asignar el puerto serie del LCD al USART3 (puerto 3 en STM32F1)
  #define LCD_SERIAL_PORT 3
#endif

// Habilitar almacenamiento de configuraciones en memoria EEPROM
#define EEPROM_SETTINGS
#define EEPROM_CHITCHAT
#define EEPROM_AUTO_INIT
