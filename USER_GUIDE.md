# Guía del Usuario - controlTachoSalero

## 🎯 Guía Rápida de Inicio

### Primer Encendido

1. **Conecta la alimentación** al Arduino (USB o adaptador 7-12V)
2. Verás el **mensaje de bienvenida** durante 2 segundos:
   ```
   ControlTacho
   Salero v1.0
   ```
3. El sistema entrará automáticamente en la **pantalla principal**

### Configuración Inicial

Antes de usar el sistema, debes configurar dos parámetros importantes:

#### 1. Configurar Altura del Tanque
1. Mide la altura total de tu tanque desde donde está el sensor hasta el fondo
2. Presiona **SELECT** en la pantalla principal
3. Presiona **UP** para entrar a "Altura Tanque"
4. Usa **UP/DOWN** para ajustar el valor (en centímetros)
5. Presiona **SELECT** o **LEFT** para guardar y salir

#### 2. Configurar Offset del Sensor
1. Mide la distancia desde el borde superior del tanque hasta el sensor
2. Presiona **SELECT** en la pantalla principal
3. Presiona **DOWN** para entrar a "Offset Sensor"
4. Usa **UP/DOWN** para ajustar el valor (en centímetros)
5. Presiona **SELECT** o **LEFT** para guardar y salir

## 📱 Navegación del Sistema

### Pantalla Principal

Esta es la pantalla que verás la mayor parte del tiempo:

```
┌────────────────┐
│Dist: 45.3 cm   │  ← Distancia medida por el sensor
│Nivel: 67%    **│  ← Porcentaje de llenado + indicador
└────────────────┘
```

**Elementos de la pantalla:**
- **Dist**: Distancia del sensor a la superficie del líquido
- **Nivel**: Porcentaje de llenado calculado
- **Indicador visual**: 
  - `   ` = 0-24%
  - `*  ` = 25-49%
  - `** ` = 50-74%
  - `***` = 75-100%

**Botones disponibles:**
- **SELECT**: Entrar al menú de configuración
- Otros botones: Sin función en esta pantalla

### Menú de Configuración

Para acceder, presiona **SELECT** desde la pantalla principal:

```
┌────────────────┐
│CONFIGURACION   │
│UP/DOWN p/elegir│
└────────────────┘
```

**Botones disponibles:**
- **UP**: Ir a configuración de altura del tanque
- **DOWN**: Ir a configuración de offset del sensor
- **LEFT** o **SELECT**: Volver a pantalla principal

### Configuración de Altura del Tanque

```
┌────────────────┐
│Altura Tanque   │
│100 cm (UP/DOWN)│
└────────────────┘
```

**Botones disponibles:**
- **UP**: Incrementar altura en 5 cm
- **DOWN**: Decrementar altura en 5 cm
- **LEFT** o **SELECT**: Volver al menú de configuración

**Rango válido**: 10 cm a 400 cm

### Configuración de Offset del Sensor

```
┌────────────────┐
│Offset Sensor   │
│5 cm (UP/DOWN)  │
└────────────────┘
```

**Botones disponibles:**
- **UP**: Incrementar offset en 1 cm
- **DOWN**: Decrementar offset en 1 cm
- **LEFT** o **SELECT**: Volver al menú de configuración

**Rango válido**: 0 cm a 50 cm

## 🔧 Calibración del Sistema

### ¿Qué es la calibración?

La calibración asegura que el sistema mide correctamente el nivel de líquido en tu tanque específico.

### Proceso de Calibración Paso a Paso

#### Paso 1: Medir la Altura Total del Tanque

1. **Con el tanque vacío**, coloca una cinta métrica desde el punto donde está instalado el sensor hasta el fondo del tanque
2. Anota esta medida (por ejemplo: 100 cm)
3. Esta será la "Altura Total" del tanque

#### Paso 2: Medir el Offset del Sensor

1. Mide la distancia desde el **borde superior del tanque** hasta el **sensor HC-SR04**
2. Anota esta medida (por ejemplo: 5 cm)
3. Este será el "Offset del Sensor"

**Nota**: El offset es importante porque el sensor normalmente está montado un poco por encima del borde del tanque.

#### Paso 3: Ingresar los Valores

1. Entra al menú de configuración (botón **SELECT**)
2. Configura la altura del tanque con el valor medido en el Paso 1
3. Configura el offset con el valor medido en el Paso 2
4. Los valores se guardan automáticamente

#### Paso 4: Verificar la Calibración

1. Llena el tanque con agua hasta un nivel conocido
2. Verifica que el porcentaje mostrado sea correcto
3. Si es necesario, ajusta los valores

### Ejemplo de Calibración

**Situación:**
- Tanque de 120 cm de altura
- Sensor montado 8 cm por encima del borde del tanque
- Tanque con agua hasta 80 cm de altura

**Configuración:**
- Altura Total: 120 cm
- Offset Sensor: 8 cm

**Cálculo del sistema:**
- Distancia medida por sensor: 48 cm (8 cm offset + 40 cm vacío)
- Nivel de líquido: 120 - (48 - 8) = 80 cm
- Porcentaje: (80 / 120) × 100 = 66.7%

## 📊 Interpretación de Lecturas

### Lecturas Normales

| Distancia Medida | Significado |
|------------------|-------------|
| Pequeña (~5-20cm) | Tanque casi lleno |
| Media (~30-70cm) | Tanque medio lleno |
| Grande (~80-120cm) | Tanque casi vacío |

### Mensajes de Error

| Mensaje | Causa | Solución |
|---------|-------|----------|
| `Error lectura` | Sensor no detecta eco | Verificar conexiones, limpiar sensor |
| `Nivel: ---%` | Cálculo inválido | Verificar configuración de altura/offset |

### Indicadores Visuales

La barra de progreso en la esquina inferior derecha proporciona una indicación visual rápida:

- `   ` : Tanque casi vacío (0-24%)
- `*  ` : Tanque con poco líquido (25-49%)
- `** ` : Tanque medio lleno (50-74%)
- `***` : Tanque casi lleno (75-100%)

## 💡 Consejos de Uso

### Para Mejores Resultados

1. **Montaje del sensor**: 
   - Instala el sensor perpendicular a la superficie del líquido
   - Centra el sensor para evitar lecturas de las paredes
   - Protege el sensor de salpicaduras directas

2. **Configuración**:
   - Mide con precisión la altura del tanque
   - Actualiza el offset si mueves el sensor
   - Verifica la calibración periódicamente

3. **Mantenimiento**:
   - Limpia el sensor regularmente (polvo puede afectar lecturas)
   - Verifica las conexiones si aparecen errores
   - Mantén el LCD alejado de la luz solar directa

### Limitaciones a Considerar

- **Espuma**: La espuma puede causar lecturas incorrectas
- **Ondas**: El agua en movimiento puede variar las lecturas
- **Temperatura**: Temperaturas extremas afectan la precisión
- **Vapor**: La condensación puede obstruir el sensor

## 🔄 Mantenimiento

### Mantenimiento Mensual

- ✅ Limpiar el sensor HC-SR04 con un paño seco
- ✅ Verificar todas las conexiones
- ✅ Comprobar que el LCD sea legible
- ✅ Verificar que los botones respondan correctamente

### Mantenimiento Trimestral

- ✅ Verificar la calibración con una medición manual
- ✅ Limpiar el LCD y ajustar contraste si es necesario
- ✅ Revisar el montaje del sensor (debe estar firme)
- ✅ Inspeccionar cables por desgaste

### Limpieza del Sensor

1. Desconecta la alimentación
2. Usa un paño suave y seco para limpiar las cápsulas ultrasónicas
3. No uses líquidos directamente en el sensor
4. Deja secar completamente antes de reconectar

## 🆘 Solución de Problemas Comunes

### El porcentaje no coincide con el nivel real

**Causas posibles:**
1. Altura del tanque mal configurada
2. Offset del sensor incorrecto
3. Sensor desalineado o movido

**Soluciones:**
1. Re-mide la altura del tanque y actualiza la configuración
2. Verifica y ajusta el offset del sensor
3. Verifica que el sensor esté bien montado y perpendicular

### Las lecturas fluctúan mucho

**Causas posibles:**
1. Superficie del líquido con ondas
2. Interferencias eléctricas
3. Conexiones flojas

**Soluciones:**
1. Espera a que el líquido se estabilice
2. Aleja cables de fuentes de interferencia (motores, etc.)
3. Verifica y asegura todas las conexiones

### El sistema se reinicia solo

**Causas posibles:**
1. Alimentación insuficiente
2. Cortocircuito
3. Cable USB defectuoso

**Soluciones:**
1. Usa una fuente de alimentación adecuada (mínimo 500mA)
2. Revisa todas las conexiones en busca de cortocircuitos
3. Prueba con otro cable USB o fuente de alimentación

### Los botones no responden bien

**Causas posibles:**
1. Botones sucios o desgastados
2. Shield mal conectado
3. Interferencia eléctrica

**Soluciones:**
1. Limpia los botones con alcohol isopropílico
2. Re-asienta el LCD Keypad Shield en el Arduino
3. Aleja de fuentes de interferencia electromagnética

## 📋 Preguntas Frecuentes (FAQ)

### ¿Puedo usar este sistema con otros líquidos además de salmuera?

Sí, el sistema funciona con cualquier líquido. La salmuera es solo el caso de uso principal.

### ¿El sensor puede dañarse con la humedad?

El HC-SR04 puede tolerar algo de humedad ambiental, pero no debe sumergirse ni recibir salpicaduras directas. Se recomienda protegerlo con una carcasa.

### ¿Puedo usar cables más largos para el sensor?

Sí, pero mantén los cables lo más cortos posible (preferiblemente <1 metro) para evitar interferencias y pérdida de señal.

### ¿Qué pasa si se corta la alimentación?

La configuración se guarda automáticamente en la EEPROM y se mantiene incluso sin alimentación. Al reconectar, el sistema usará la última configuración guardada.

### ¿Puedo cambiar los pines del sensor?

Sí, pero necesitarás modificar el código. Busca las líneas:
```cpp
#define TRIG_PIN 2
#define ECHO_PIN 3
```
Y cámbialas a los pines que desees usar.

### ¿El sistema consume mucha energía?

No, el consumo total es de aproximadamente 80mA, lo que es muy bajo. Puede funcionar con baterías para aplicaciones portátiles.

### ¿Funciona con tanques de cualquier forma?

Funciona mejor con tanques cilíndricos o rectangulares. Tanques con formas irregulares pueden requerir calibración adicional.

## 🔐 Seguridad

### Precauciones Eléctricas

- ⚠️ No expongas el sistema a agua o humedad excesiva
- ⚠️ Usa solo fuentes de alimentación certificadas
- ⚠️ No modifiques el circuito sin conocimiento adecuado
- ⚠️ Desconecta la alimentación antes de hacer cambios

### Instalación Segura

- ⚠️ Monta el sensor firmemente para evitar caídas
- ⚠️ Asegura todos los cables para evitar tropiezos
- ⚠️ Protege el sistema de la intemperie
- ⚠️ No instales cerca de fuentes de calor

## 📞 Soporte

Si tienes problemas que no puedes resolver:

1. Revisa esta guía completamente
2. Consulta el archivo CIRCUIT_DIAGRAM.md para verificar conexiones
3. Abre un [issue en GitHub](https://github.com/pingitzern/controlTachoSalero/issues)
4. Incluye:
   - Descripción detallada del problema
   - Fotos de tu instalación
   - Configuración actual (altura, offset)
   - Cualquier mensaje de error

---

**Versión del documento**: 1.0  
**Última actualización**: 2025-10-25
