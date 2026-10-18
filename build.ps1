# Script de Compilación Automática de Marlin para Creality v4.2.7
# Lee los parámetros definidos en PRINTER_CONFIG.h y genera el .bin en build/creality_v427/

$ErrorActionPreference = "Stop"

Write-Host "==========================================================" -ForegroundColor Cyan
Write-Host " Compilando Marlin Firmware para Creality v4.2.7...       " -ForegroundColor Cyan
Write-Host " Parametros leidos desde: PRINTER_CONFIG.h                " -ForegroundColor Cyan
Write-Host "==========================================================" -ForegroundColor Cyan

# Ejecutar PlatformIO a traves del entorno aislado de Python 3.12
uvx --python 3.12 platformio run -e STM32F103RE_creality

if ($LASTEXITCODE -eq 0) {
    # Buscar el binario mas reciente generado
    $binFile = Get-ChildItem -Path ".pio\build\STM32F103RE_creality\firmware-*.bin" | Sort-Object LastWriteTime -Descending | Select-Object -First 1

    if ($binFile) {
        $destPath = "build\creality_v427\$($binFile.Name)"
        $destLatest = "build\creality_v427\firmware.bin"

        Copy-Item $binFile.FullName -Destination $destPath -Force
        Copy-Item $binFile.FullName -Destination $destLatest -Force

        Write-Host ""
        Write-Host "==========================================================" -ForegroundColor Green
        Write-Host " [EXITO] Compilacion completada correctamente!" -ForegroundColor Green
        Write-Host " Archivo generado: $destPath" -ForegroundColor Green
        Write-Host " Archivo latest:   $destLatest" -ForegroundColor Green
        Write-Host " Listo para copiar a tu tarjeta MicroSD FAT32." -ForegroundColor Green
        Write-Host "==========================================================" -ForegroundColor Green
    }
} else {
    Write-Host ""
    Write-Host "[ERROR] La compilacion fallo. Revisa los mensajes anteriores." -ForegroundColor Red
    exit 1
}
