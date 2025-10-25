# Ejemplos de Uso - controlTachoSalero

## 📝 Casos de Uso Comunes

### Ejemplo 1: Tanque de Salmuera Doméstico

**Escenario:**
Un tanque de salmuera para descalcificador de agua de 80 cm de altura, con el sensor montado 10 cm por encima del borde superior del tanque.

**Configuración:**
```
Altura Total: 80 cm
Offset Sensor: 10 cm
```

**Lecturas típicas:**

| Nivel Real | Distancia Sensor | Cálculo | Porcentaje |
|------------|------------------|---------|------------|
| Vacío (0 cm) | 90 cm | 80 - (90 - 10) = 0 cm | 0% |
| Medio (40 cm) | 50 cm | 80 - (50 - 10) = 40 cm | 50% |
| Lleno (80 cm) | 10 cm | 80 - (10 - 10) = 80 cm | 100% |

### Ejemplo 2: Tanque de Agua Grande

**Escenario:**
Un tanque de agua de 200 cm de altura para riego, con el sensor montado 5 cm por encima del borde.

**Configuración:**
```
Altura Total: 200 cm
Offset Sensor: 5 cm
```

**Lecturas típicas:**

| Nivel Real | Distancia Sensor | Cálculo | Porcentaje |
|------------|------------------|---------|------------|
| Vacío (0 cm) | 205 cm | 200 - (205 - 5) = 0 cm | 0% |
| 1/4 lleno (50 cm) | 155 cm | 200 - (155 - 5) = 50 cm | 25% |
| Medio (100 cm) | 105 cm | 200 - (105 - 5) = 100 cm | 50% |
| 3/4 lleno (150 cm) | 55 cm | 200 - (55 - 5) = 150 cm | 75% |
| Lleno (200 cm) | 5 cm | 200 - (5 - 5) = 200 cm | 100% |

### Ejemplo 3: Boya Pequeña

**Escenario:**
Una boya pequeña de 50 cm de altura, con el sensor montado directamente en el borde (sin offset).

**Configuración:**
```
Altura Total: 50 cm
Offset Sensor: 0 cm
```

**Lecturas típicas:**

| Nivel Real | Distancia Sensor | Cálculo | Porcentaje |
|------------|------------------|---------|------------|
| Vacío (0 cm) | 50 cm | 50 - (50 - 0) = 0 cm | 0% |
| Medio (25 cm) | 25 cm | 50 - (25 - 0) = 25 cm | 50% |
| Lleno (50 cm) | 0 cm | 50 - (0 - 0) = 50 cm | 100% |

## 🔧 Escenarios de Instalación

### Instalación Tipo A: Montaje Superior

```
    Sensor HC-SR04
         ↓
    ┌────┴────┐
    │    ═    │ ← Offset (distancia sensor a borde)
    ├─────────┤ ← Borde del tanque
    │         │
    │  ╔═══╗  │ ← Altura Total
    │  ║░░░║  │    (sensor a fondo)
    │  ║░░░║  │
    │  ║░░░║  │ ← Nivel de líquido
    │  ╚═══╝  │
    └─────────┘
```

**Ventajas:**
- Instalación más simple
- Sensor protegido de salpicaduras
- Fácil acceso para mantenimiento

**Desventajas:**
- Requiere estructura para montar el sensor
- Mayor offset a configurar

### Instalación Tipo B: Montaje al Ras

```
    ┌─────────┐ ← Sensor montado al ras del borde
    │ Sensor  │
    ├─────────┤ ← Borde del tanque (offset = 0)
    │         │
    │  ╔═══╗  │ ← Altura Total
    │  ║░░░║  │
    │  ║░░░║  │
    │  ║░░░║  │ ← Nivel de líquido
    │  ╚═══╝  │
    └─────────┘
```

**Ventajas:**
- Configuración más simple (offset = 0)
- Aprovecha todo el rango del tanque

**Desventajas:**
- Sensor más expuesto a salpicaduras
- Requiere modificación del tanque

### Instalación Tipo C: Montaje Lateral

```
         Sensor HC-SR04
              ↓
    ┌─────────┼─────┐
    │         ↓     │
    │  ╔═══════════╗│
    │  ║░░░░░░░░░░░║│ ← Líquido
    │  ║░░░░░░░░░░░║│
    │  ╚═══════════╝│
    └───────────────┘
```

**Nota:** Esta configuración NO es recomendada. El sensor debe apuntar verticalmente hacia abajo para obtener lecturas precisas.

## 💻 Ejemplos de Código (Modificaciones Opcionales)

### Ejemplo 1: Cambiar el Intervalo de Lectura

Si quieres mediciones más frecuentes o menos frecuentes:

```cpp
// En el código original:
const unsigned long INTERVALO_LECTURA = 500;  // 500ms = 2 veces por segundo

// Para mediciones más frecuentes (5 veces por segundo):
const unsigned long INTERVALO_LECTURA = 200;  // 200ms

// Para mediciones menos frecuentes (1 vez por segundo):
const unsigned long INTERVALO_LECTURA = 1000; // 1000ms
```

### Ejemplo 2: Ajustar Incrementos de Configuración

Si quieres cambiar cuánto incrementan/decrementan los valores:

```cpp
// Para altura del tanque (original incrementa de 5 en 5):
case MENU_ALTURA:
  if (boton == btnUP) {
    alturaTotal += 10;  // Cambiar a incrementos de 10 cm
    // ...
  } else if (boton == btnDOWN) {
    alturaTotal -= 10;  // Cambiar a decrementos de 10 cm
    // ...
  }
```

### Ejemplo 3: Agregar Alarma Sonora

Si quieres añadir un buzzer para alertas:

```cpp
// Al inicio del código, agregar:
#define BUZZER_PIN 11
#define NIVEL_ALARMA_BAJO 20  // Alarma cuando nivel < 20%

// En setup(), agregar:
pinMode(BUZZER_PIN, OUTPUT);

// En loop(), después de calcular porcentaje:
if (porcentaje >= 0 && porcentaje < NIVEL_ALARMA_BAJO) {
  tone(BUZZER_PIN, 1000, 100);  // Beep corto
  delay(100);
}
```

### Ejemplo 4: Agregar Salida de Relé

Para controlar una bomba automáticamente:

```cpp
// Al inicio del código:
#define RELE_PIN 12
#define NIVEL_ACTIVAR 30   // Activar bomba cuando nivel < 30%
#define NIVEL_DESACTIVAR 80 // Desactivar bomba cuando nivel > 80%

// En setup():
pinMode(RELE_PIN, OUTPUT);
digitalWrite(RELE_PIN, LOW);

// En loop(), después de calcular porcentaje:
static bool bombaActiva = false;

if (porcentaje >= 0) {
  if (porcentaje < NIVEL_ACTIVAR && !bombaActiva) {
    digitalWrite(RELE_PIN, HIGH);  // Activar bomba
    bombaActiva = true;
  } else if (porcentaje > NIVEL_DESACTIVAR && bombaActiva) {
    digitalWrite(RELE_PIN, LOW);   // Desactivar bomba
    bombaActiva = false;
  }
}
```

## 📊 Tablas de Referencia Rápida

### Valores de Botones del LCD Keypad Shield

| Botón  | Valor ADC Min | Valor ADC Max | Valor Típico |
|--------|---------------|---------------|--------------|
| RIGHT  | 0             | 50            | 0            |
| UP     | 50            | 195           | 131          |
| DOWN   | 195           | 380           | 307          |
| LEFT   | 380           | 555           | 481          |
| SELECT | 555           | 790           | 721          |
| NONE   | 790           | 1023          | 1023         |

### Rangos de Configuración

| Parámetro | Mínimo | Máximo | Por Defecto | Incremento |
|-----------|--------|--------|-------------|------------|
| Altura Total | 10 cm | 400 cm | 100 cm | 5 cm |
| Offset Sensor | 0 cm | 50 cm | 5 cm | 1 cm |

### Tiempos del Sistema

| Función | Tiempo | Propósito |
|---------|--------|-----------|
| Intervalo de Lectura | 500 ms | Frecuencia de medición del sensor |
| Debounce de Botones | 200 ms | Evitar múltiples pulsaciones |
| Timeout de Sensor | 30 ms | Tiempo máximo de espera del eco |
| Mensaje de Bienvenida | 2000 ms | Duración del mensaje inicial |
| Delay del Loop | 100 ms | Tiempo entre ciclos |

### Direcciones EEPROM

| Dato | Dirección | Bytes | Descripción |
|------|-----------|-------|-------------|
| Altura Total | 0-1 | 2 | Valor entero (int) |
| Offset Sensor | 2-3 | 2 | Valor entero (int) |
| Flag de Inicialización | 4 | 1 | Byte con valor 42 |

## 🎓 Casos de Estudio

### Caso 1: Optimización para Tanque Pequeño

**Problema:**
Un usuario tiene un tanque de solo 30 cm y las lecturas fluctúan mucho.

**Solución:**
1. Reducir el intervalo de lectura para más estabilidad:
   ```cpp
   const unsigned long INTERVALO_LECTURA = 1000; // 1 segundo
   ```
2. Asegurar que el sensor esté bien centrado
3. Usar incrementos de configuración más finos para altura

### Caso 2: Instalación en Ambiente Húmedo

**Problema:**
El sensor se instala en un sótano húmedo y las lecturas son erráticas.

**Solución:**
1. Proteger el sensor con una carcasa plástica transparente
2. Asegurar buena ventilación alrededor del sensor
3. Agregar validación adicional en el código:
   ```cpp
   // Promediar 3 lecturas para mayor estabilidad
   float medirDistanciaEstable() {
     float suma = 0;
     int lecturas = 0;
     for(int i = 0; i < 3; i++) {
       float dist = medirDistancia();
       if(dist > 0) {
         suma += dist;
         lecturas++;
       }
       delay(50);
     }
     if(lecturas > 0) {
       return suma / lecturas;
     }
     return -1;
   }
   ```

### Caso 3: Tanque con Salmuera Concentrada

**Problema:**
La salmuera muy concentrada puede formar cristales que afectan el sensor.

**Solución:**
1. Instalar el sensor con mayor offset para evitar salpicaduras
2. Limpiar el sensor regularmente (cada 2 semanas)
3. Considerar una tapa protectora removible
4. Agregar un recordatorio visual en el LCD para mantenimiento

## 🔗 Integraciones Posibles

### Con Arduino IoT Cloud

Puedes extender este proyecto para enviar datos a la nube:
- Monitoreo remoto del nivel del tanque
- Alertas por email o notificación push
- Registro histórico de niveles

### Con Home Assistant

Integra el sistema con tu smart home:
- Automatizaciones basadas en el nivel
- Dashboards visuales
- Control de bombas y válvulas

### Con Display OLED

Reemplaza el LCD por un display OLED:
- Mejor contraste y visibilidad
- Posibilidad de gráficos
- Menor consumo energético

## 📝 Plantilla de Registro de Calibración

```
REGISTRO DE CALIBRACIÓN - controlTachoSalero
============================================

Fecha: _______________
Ubicación del tanque: _________________________
Tipo de líquido: _____________________________

MEDICIONES:
- Altura total del tanque (fondo a sensor): ______ cm
- Distancia sensor a borde superior: ______ cm (offset)
- Distancia sensor a tapa/cubierta: ______ cm

CONFIGURACIÓN INGRESADA:
- Altura Total: ______ cm
- Offset Sensor: ______ cm

VERIFICACIÓN:
- Con tanque VACÍO:
  Distancia mostrada: ______ cm
  Porcentaje mostrado: ______ %
  ¿Es correcto? □ Sí □ No

- Con tanque MEDIO (50%):
  Distancia mostrada: ______ cm
  Porcentaje mostrado: ______ %
  ¿Es correcto? □ Sí □ No

- Con tanque LLENO:
  Distancia mostrada: ______ cm
  Porcentaje mostrado: ______ %
  ¿Es correcto? □ Sí □ No

AJUSTES REALIZADOS:
_________________________________________________
_________________________________________________

NOTAS ADICIONALES:
_________________________________________________
_________________________________________________
_________________________________________________

Calibración realizada por: _____________________
```

---

**Última actualización**: 2025-10-25
