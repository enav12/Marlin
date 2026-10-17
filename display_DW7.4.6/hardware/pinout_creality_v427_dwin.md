# Conexión Física: Creality v4.2.7 y Pantalla DWIN (DW7.4.6)

Este documento describe el esquema de conexión y cableado entre la placa base silenciosa **Creality v4.2.7** y la pantalla táctil **DWIN** (DGUS) con firmware **DW7.4.6**.

---

## 1. Conectores y Señales

La placa Creality v4.2.7 dispone del conector **EXP1** (cabezal IDC de 10 pines). La pantalla DWIN táctil requiere 4 líneas esenciales para comunicarse con la placa base:
1. **VCC (+5V)**: Alimentación.
2. **GND**: Masa / Tierra común.
3. **TX (Transmisión)**: Placa TX -> Pantalla RX.
4. **RX (Recepción)**: Placa RX <- Pantalla TX.

```
       Conector EXP1 (Creality v4.2.7)
                +---------+
      (PB0)  1  |  o   o  |  2  (PB1)
   (TX3/PB10) 3  |  o   o  |  4  (RX3/PB11)
      (PA4)  5  |  o   o  |  6  (PA5)
      (PA6)  7  |  o   o  |  8  (PA7)
      (GND)  9  |  o   o  | 10 (+5V)
                +----+----+
                     | muesca
```

| Pin EXP1 (4.2.7) | Función STM32 | Destino en Pantalla DWIN | Descripción |
| :---: | :---: | :---: | :--- |
| **Pin 10** | **+5V** | **VCC (+5V)** | Alimentación lógica y retroiluminación |
| **Pin 9** | **GND** | **GND** | Tierra / Masa común |
| **Pin 3** | **PB10 (USART3 TX)** | **RX** | Datos enviados desde Marlin a la Pantalla |
| **Pin 4** | **PB11 (USART3 RX)** | **TX** | Comandos táctiles desde Pantalla a Marlin |

> [!WARNING]
> Nunca inviertas +5V y GND. Verifica siempre la orientación de la muesca del conector IDC de 10 pines antes de encender la máquina.

---

## 2. Tipos de Cable de Conexión

1. **Cable plano de 10 pines (Ribbon 10P)**:
   Si utilizas la pantalla en un chasis donde el conector es directo IDC-10 (como en Ender 5 Plus o CR-10S Pro), el cable plano estándar de 10 pines funciona directamente con el conector EXP1.
2. **Conector JST-XH de 4/5 pines (Touchscreen)**:
   Si tu pantalla DWIN tiene un conector hembra JST de 4 pines (VCC, TX, RX, GND), utiliza un cable adaptador que conecte:
   - JST Pin 1 (VCC) -> EXP1 Pin 10
   - JST Pin 2 (TX)  -> EXP1 Pin 4 (PB11 RX)
   - JST Pin 3 (RX)  -> EXP1 Pin 3 (PB10 TX)
   - JST Pin 4 (GND) -> EXP1 Pin 9
