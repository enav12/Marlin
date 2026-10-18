; =============================================================================
; PRUEBA MANUAL INTERACTIVA DEL CR TOUCH (DESDE PANTALLA TÁCTIL)
; Archivo: 01_test_cr_touch_manual.gcode
; Ubicación: build/01_test_cr_touch_manual.gcode
;
; INSTRUCCIONES DE USO:
; 1. Copia este archivo a la raíz de tu tarjeta MicroSD.
; 2. En la pantalla táctil de tu impresora, entra al menú "Imprimir" / "Print".
; 3. Toca "01_test_cr_touch_manual.gcode" y confirma.
; 4. El cabezal se elevará a una altura cómoda en el centro.
; 5. La aguja del CR Touch bajará (se desplegará).
; 6. Tienes 30 segundos para presionar suavemente la punta metálica con tu dedo.
; 7. Cuando detecte la presión, la aguja subirá inmediatamente, la pantalla
;    mostrará "CR Touch: OK DETECTADO!" y emitirá un pitido de éxito.
; =============================================================================

M117 Preparando prueba...
M300 S800 P150          ; Pitido inicial de aviso
G4 P500

; --- Posicionamiento seguro para acceso manual ---
G90                     ; Coordenadas absolutas
G28 X Y                 ; Homing en X e Y
G1 X110 Y110 F4000      ; Centra el cabezal frente al usuario
G91                     ; Coordenadas relativas
G1 Z60 F1500            ; Eleva el eje Z 60 mm para dejar espacio cómodo a tu mano
G90                     ; Coordenadas absolutas

; --- Mensaje en pantalla antes de iniciar ---
M117 CR Touch: Toque punta!
M300 S1000 P200
G4 P1000                ; Pausa de 1 segundo

; --- Ejecución de la prueba interactiva M43 S ---
; Despliega la aguja, espera la pulsación de tu mano (hasta 30s),
; detecta el cambio de estado óptico en PB1, pita al detectar y retrae la aguja.
M43 S

; --- Mensaje final de seguridad ---
G4 P2000
M117 Prueba completada
M300 S1200 P100
G4 P150
M300 S1500 P200
