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

// Comunicación Serie:
// Puerto 1: Conexión USB al computador (CH340 / USART1)
#define SERIAL_PORT 1
#define BAUDRATE 115200

// Nota: No definir SERIAL_PORT_2 como 3, ya que el puerto serie de la pantalla
// se asigna exclusivamente mediante LCD_SERIAL_PORT en Configuration_adv.h.

// Interfaz Gráfica DGUS / DWIN para pantalla táctil
// Variante compatible con el juego de iconos DW7.4.6:
#define DGUS_LCD_UI_ORIGIN

// Soporte de modulación por software del ventilador (requerido por hardware 4.2.7)
#define FAN_SOFT_PWM

// =============================================================================
// 2. CAMBIOS EN: Marlin/Configuration_adv.h
// =============================================================================

#if HAS_DGUS_LCD
  // Asignar el puerto serie del LCD al USART3 (conector EXP1 pines PB10 / PB11)
  #define LCD_SERIAL_PORT 3
  #define LCD_BAUDRATE 115200
#endif

// Habilitar almacenamiento de configuraciones en memoria EEPROM
#define EEPROM_SETTINGS
#define EEPROM_CHITCHAT
#define EEPROM_AUTO_INIT

// Babystepping para calibración en vivo del Z-Offset con CR Touch
#define BABYSTEPPING
#define BABYSTEP_ZPROBE_OFFSET
