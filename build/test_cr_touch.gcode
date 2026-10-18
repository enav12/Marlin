; =============================================================================
; ARCHIVO DE PRUEBA Y DIAGNÓSTICO DEL SENSOR CR TOUCH / BLTOUCH
; Archivo: test_cr_touch.gcode
; Ubicación: build/test_cr_touch.gcode
;
; Puedes copiar este archivo a tu tarjeta MicroSD y ejecutarlo ("imprimirlo")
; desde el menú de la pantalla, o enviarlo por terminal serie (OctoPrint / Pronterface).
; =============================================================================

M117 Iniciando Test CR Touch...
G4 P1000

; --- PASO 1: Prueba de despliegue y retracción mecánica ---
M117 Test 1: Desplegando aguja...
M280 P0 S10      ; Despliega la aguja metálica
G4 P2000         ; Espera 2 segundos para verificar visualmente que bajó

M117 Test 1: Retrayendo aguja...
M280 P0 S90      ; Retrae la aguja
G4 P2000         ; Espera 2 segundos para verificar que subió

; --- PASO 2: Auto-prueba interna del sensor (Self-Test) ---
M117 Test 2: Auto-prueba (Self-Test)...
M280 P0 S120     ; Activa el modo de auto-prueba continuo (sube y baja 10 veces)
G4 P4000         ; Permite que realice las oscilaciones de prueba
M280 P0 S90      ; Detiene la auto-prueba y guarda la aguja
G4 P1000

; --- PASO 3: Homing seguro en el centro de la cama ---
M117 Test 3: Auto Home seguro G28...
G28              ; Homing X, Y y luego Z en el centro de la cama (110, 110 mm)
G4 P1000

; --- PASO 4: Prueba de precisión y repetibilidad M48 (10 puntos) ---
M117 Test 4: Prueba de Repetibilidad M48...
M48 P10 X110 Y110 V2  ; 10 palpados en el centro de la cama con cálculo de desviación estándar
G4 P1000

; --- PASO 5: Malla completa de nivelación G29 (3x3 = 9 puntos) ---
M117 Test 5: Malla de nivelacion G29...
G29              ; Palpa los 9 puntos de la cama y genera la matriz de compensación

; --- FINALIZACIÓN: Elevación segura y pitido de confirmación ---
G90              ; Coordenadas absolutas
G1 Z60 F2400     ; Eleva el cabezal a 60 mm de altura
G1 X10 Y10 F4000 ; Aparca el cabezal en una esquina para inspección
M117 CR Touch Test: EXITOSO!
M300 S1000 P300  ; Pitido sonoro de éxito
