# Diagrama de Circuito - controlTachoSalero

## 📐 Esquema de Conexiones

### Vista General del Sistema

```
                    ┌─────────────────────────┐
                    │     Arduino UNO         │
                    │                         │
                    │  ┌──────────────────┐   │
                    │  │ LCD Keypad Shield│   │
                    │  │   16x2 Display   │   │
                    │  │   [  BUTTONS  ]  │   │
                    │  └──────────────────┘   │
                    │                         │
                    │  D2 ────────┐           │
                    │  D3 ────┐   │           │
                    │  5V ──┐ │   │           │
                    │  GND ─┼─┼───┼──         │
                    └───────┼─┼───┼───────────┘
                            │ │   │
                            │ │   │
                    ┌───────┼─┼───┼───────────┐
                    │       │ │   │           │
                    │ HC-SR04 Ultrasonic      │
                    │       │ │   │           │
                    │  VCC ─┘ │   │           │
                    │  TRIG ──┘   │           │
                    │  ECHO ──────┘           │
                    │  GND                    │
                    └─────────────────────────┘
```

## 🔌 Conexiones Detalladas

### Arduino UNO a Sensor HC-SR04

| HC-SR04 Pin | Función | Arduino Pin | Cable Sugerido |
|-------------|---------|-------------|----------------|
| VCC         | +5V     | 5V          | Rojo           |
| TRIG        | Trigger | D2          | Amarillo       |
| ECHO        | Echo    | D3          | Verde          |
| GND         | Ground  | GND         | Negro          |

### LCD Keypad Shield

El LCD Keypad Shield se monta directamente sobre el Arduino UNO (shield apilable).

#### Pines Utilizados por el Shield:

| Función        | Pin Arduino | Descripción                          |
|----------------|-------------|--------------------------------------|
| LCD RS         | D8          | Register Select                      |
| LCD Enable     | D9          | Enable Signal                        |
| LCD D4         | D4          | Data Bit 4                          |
| LCD D5         | D5          | Data Bit 5                          |
| LCD D6         | D6          | Data Bit 6                          |
| LCD D7         | D7          | Data Bit 7                          |
| LCD Backlight  | D10         | Backlight Control                    |
| Buttons ADC    | A0          | Analog input for button reading      |

#### Botones del Shield:

Los botones están conectados a una red resistiva en el pin A0 (analógico):

| Botón  | Valor ADC Aproximado | Función en el Sistema               |
|--------|----------------------|-------------------------------------|
| RIGHT  | ~0                   | No usado en menú principal          |
| UP     | ~131                 | Incrementar valores / Navegar arriba|
| DOWN   | ~307                 | Decrementar valores / Navegar abajo |
| LEFT   | ~481                 | Volver al menú anterior             |
| SELECT | ~721                 | Entrar al menú / Confirmar          |
| NONE   | ~1023                | Sin botón presionado                |

## 🔧 Montaje Físico

### Paso 1: Preparar el Arduino UNO
1. Coloca el Arduino UNO en una superficie estable o caja de proyecto

### Paso 2: Montar el LCD Keypad Shield
1. Alinea los pines del LCD Keypad Shield con los headers del Arduino
2. Presiona firmemente hasta que el shield quede bien asentado
3. Verifica que todos los pines estén correctamente insertados

### Paso 3: Conectar el Sensor HC-SR04
1. Conecta el cable rojo (VCC) del sensor al pin 5V del Arduino
2. Conecta el cable negro (GND) del sensor al pin GND del Arduino
3. Conecta el cable amarillo (TRIG) del sensor al pin D2 del Arduino
4. Conecta el cable verde (ECHO) del sensor al pin D3 del Arduino

**Nota**: Como el LCD Shield cubre los pines, puedes:
- Usar los pines que atraviesan el shield (si están disponibles)
- Soldar cables directamente a los pines antes de montar el shield
- Usar un cable extensor de pines (headers apilables)

### Paso 4: Instalación en el Tanque
1. Monta el sensor HC-SR04 en la parte superior del tanque
2. El sensor debe apuntar perpendicularmente hacia abajo
3. Protege el sensor de salpicaduras directas (usar carcasa si es necesario)
4. Asegura todos los cables para evitar desconexiones

## 🔍 Notas Técnicas

### Compatibilidad del Sensor HC-SR04
- **Voltaje de operación**: 5V DC
- **Corriente de trabajo**: 15mA
- **Ángulo de medición**: 15 grados
- **Rango de distancia**: 2cm a 400cm
- **Precisión**: ±3mm

### Consumo de Corriente Total
- Arduino UNO: ~45mA
- LCD Keypad Shield: ~20mA (con backlight)
- HC-SR04: ~15mA (durante medición)
- **Total**: ~80mA

### Fuentes de Alimentación Compatibles
1. **USB** (recomendado para desarrollo):
   - 5V, mínimo 500mA
   - Conectar al puerto USB del Arduino

2. **Adaptador externo** (recomendado para instalación permanente):
   - 7-12V DC
   - Mínimo 250mA
   - Conectar al jack de alimentación del Arduino
   - El regulador del Arduino proporciona 5V estable

## ⚠️ Precauciones

### Instalación Eléctrica
- ✅ Verificar polaridad antes de conectar la alimentación
- ✅ No invertir VCC y GND del sensor (puede dañarlo)
- ✅ Asegurar buenas conexiones para evitar falsos contactos
- ✅ Usar cables de calibre apropiado (22-24 AWG)

### Instalación Mecánica
- ✅ Montar el sensor firmemente para evitar vibraciones
- ✅ Mantener el sensor limpio (no obstruir las cápsulas ultrasónicas)
- ✅ Evitar superficies muy irregulares debajo del sensor
- ✅ Proteger de humedad excesiva y salpicaduras

### Limitaciones
- ❌ El sensor no funciona bien con superficies muy inclinadas
- ❌ La espuma puede causar lecturas erróneas
- ❌ Superficies muy absorbentes pueden reducir el alcance
- ❌ Temperaturas extremas (<0°C o >50°C) afectan la precisión

## 🛠️ Solución de Problemas de Hardware

### Problema: LCD no enciende
- **Causa**: Shield mal conectado o alimentación insuficiente
- **Solución**: Verificar que el shield esté bien montado y la alimentación sea adecuada

### Problema: LCD sin contraste
- **Causa**: Potenciómetro de contraste mal ajustado
- **Solución**: Usar un destornillador pequeño para ajustar el potenciómetro en el shield

### Problema: Sensor no mide
- **Causa**: Conexiones incorrectas en TRIG o ECHO
- **Solución**: Verificar que TRIG esté en D2 y ECHO en D3

### Problema: Mediciones inconsistentes
- **Causa**: Cables largos, interferencia o sensor defectuoso
- **Solución**: Usar cables cortos (<50cm), separar de cables de potencia, verificar sensor

## 📏 Dimensiones y Especificaciones

### Arduino UNO
- Tamaño: 68.6mm x 53.4mm
- Peso: ~25g

### LCD Keypad Shield
- Tamaño: Similar al Arduino UNO
- Display: 16 caracteres x 2 líneas
- Peso: ~35g

### HC-SR04
- Tamaño: 45mm x 20mm x 15mm
- Distancia entre cápsulas: 25mm
- Peso: ~8g

### Caja de Proyecto Recomendada
- Tamaño mínimo: 100mm x 70mm x 40mm
- Material: Plástico ABS
- Considerar agujeros para: USB, alimentación, cables del sensor, ventilación

## 📷 Referencias Visuales

### Distribución de Pines Arduino UNO
```
         Arduino UNO
    ┌─────────────────────┐
    │                     │
    │  DIGITAL (PWM~)     │
    │  D0  D1  D2* D3*    │
    │  D4  D5  D6  D7     │
    │  D8  D9  D10 D11    │
    │  D12 D13            │
    │                     │
    │  ANALOG IN          │
    │  A0* A1  A2  A3     │
    │  A4  A5             │
    │                     │
    │  POWER              │
    │  5V* GND* GND VIN   │
    └─────────────────────┘

    * = Pines utilizados por el proyecto
```

### HC-SR04 Vista Frontal
```
    ┌─────────────────────┐
    │                     │
    │   ○           ○     │  ← Transductores
    │  (TX)       (RX)    │     ultrasónicos
    │                     │
    │  VCC TRIG ECHO GND  │  ← Pines
    └─────────────────────┘
```

## 🔗 Enlaces Útiles

- [Datasheet HC-SR04](https://cdn.sparkfun.com/datasheets/Sensors/Proximity/HCSR04.pdf)
- [Arduino UNO Pinout](https://content.arduino.cc/assets/Pinout-UNOrev3_latest.pdf)
- [LiquidCrystal Library Reference](https://www.arduino.cc/en/Reference/LiquidCrystal)
- [EEPROM Library Reference](https://www.arduino.cc/en/Reference/EEPROM)

---

**Última actualización**: 2025-10-25
