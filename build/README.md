# Proyectos de Instalación (`build/`)

En esta carpeta se organizan todos los subproyectos y paquetes listos para ser instalados y flasheados en el hardware de la impresora:

---

## Estructura de Proyectos de Instalación

```
build/
├── README.md                      # Este documento general
├── creality_v427/                 # Proyecto de instalación de firmware para la placa base v4.2.7
│   └── README.md                  # Instrucciones de flasheo vía MicroSD (archivo .bin)
└── display_DW7.4.6/               # Proyecto de instalación para la pantalla táctil DWIN
    ├── README.md                  # Flujo de trabajo y arquitectura
    ├── DWIN_SET/                  # Recursos gráficos y fuentes para la MicroSD de la pantalla
    │   └── README_DWIN_SET.md
    ├── hardware/                  # Esquema de cableado entre placa v4.2.7 y display DWIN
    │   └── pinout_creality_v427_dwin.md
    └── marlin_integration/        # Parches de código serie para Marlin
        └── Configuration_DW7.4.6_patch.h
```

---

## Resumen del Proceso de Instalación

1. **Pantalla DWIN**:
   - Usar el contenido de [`build/display_DW7.4.6/DWIN_SET/`](file:///c:/Enavarrete/Proyectos/Marlin/build/display_DW7.4.6/DWIN_SET) para flashear la pantalla mediante su ranura MicroSD interna.
2. **Placa Creality v4.2.7**:
   - Compilar Marlin y colocar el binario resultante en [`build/creality_v427/`](file:///c:/Enavarrete/Proyectos/Marlin/build/creality_v427) para flashear la placa base mediante la ranura MicroSD externa.
3. **Conexión Física**:
   - Conectar la pantalla a la placa siguiendo el diagrama de [pinout en `build/display_DW7.4.6/hardware/`](file:///c:/Enavarrete/Proyectos/Marlin/build/display_DW7.4.6/hardware/pinout_creality_v427_dwin.md).
