# controlTachoSalero

Medidor de nivel de salmuera con Arduino UNO, LCD Keypad Shield 16x2 y sensor ultrasónico HC-SR04.

## 📋 Descripción

**controlTachoSalero** es un sistema de medición de nivel de líquido diseñado para controlar tanques de salmuera o boyas domésticas. Utiliza un sensor ultrasónico para medir la distancia al líquido y calcula el porcentaje de llenado del tanque. El sistema incluye un menú interactivo para configurar los parámetros del tanque y guarda la configuración en la EEPROM del Arduino.

## 🔧 Hardware Necesario

- **Arduino UNO** (o compatible)
- **LCD Keypad Shield 16x2** (con botones: SELECT, UP, DOWN, LEFT, RIGHT)
- **Sensor Ultrasónico HC-SR04**
- Cables de conexión
- Fuente de alimentación (USB o externa 7-12V)

## 📐 Conexiones

### Sensor HC-SR04

| Pin HC-SR04 | Pin Arduino |
|-------------|-------------|
| VCC         | 5V          |
| GND         | GND         |
| TRIG        | D2          |
| ECHO        | D3          |

### LCD Keypad Shield

El LCD Keypad Shield se conecta directamente sobre el Arduino UNO utilizando todos los pines disponibles. Las conexiones principales son:

| Función    | Pin Arduino |
|------------|-------------|
| LCD RS     | D8          |
| LCD Enable | D9          |
| LCD D4     | D4          |
| LCD D5     | D5          |
| LCD D6     | D6          |
| LCD D7     | D7          |
| Botones    | A0          |
| Backlight  | D10         |

## 🚀 Instalación

1. **Instalar Arduino IDE**: Descarga e instala el [Arduino IDE](https://www.arduino.cc/en/software) en tu computadora.

2. **Clonar el repositorio**:
   ```bash
   git clone https://github.com/pingitzern/controlTachoSalero.git
   ```

3. **Abrir el sketch**: Abre el archivo `controlTachoSalero.ino` en el Arduino IDE.

4. **Instalar librerías**: El proyecto utiliza librerías estándar de Arduino que vienen preinstaladas:
   - `LiquidCrystal.h` (para el LCD)
   - `EEPROM.h` (para guardar configuración)

5. **Conectar el hardware**: Ensambla el circuito según el diagrama de conexiones.

6. **Cargar el código**: 
   - Conecta el Arduino UNO a tu computadora mediante USB
   - Selecciona el puerto correcto en `Tools > Port`
   - Selecciona la placa `Arduino UNO` en `Tools > Board`
   - Haz clic en el botón "Upload" (→)

## 📱 Uso

### Pantalla Principal

Al encender el sistema, se muestra la pantalla principal con:
- **Línea 1**: Distancia medida por el sensor en centímetros
- **Línea 2**: Porcentaje de llenado del tanque con indicador visual

Ejemplo:
```
Dist: 45.3 cm
Nivel: 67%    **
```

### Acceso al Menú de Configuración

1. Presiona el botón **SELECT** en la pantalla principal
2. Usa los botones **UP/DOWN** para seleccionar:
   - **UP**: Configurar altura del tanque
   - **DOWN**: Configurar offset del sensor
3. Presiona **LEFT** o **SELECT** para volver atrás

### Configurar Altura del Tanque

1. Desde el menú de configuración, presiona **UP**
2. Usa **UP/DOWN** para ajustar la altura total del tanque (10-400 cm)
3. El valor se guarda automáticamente en EEPROM
4. Presiona **LEFT** o **SELECT** para volver al menú

### Configurar Offset del Sensor

1. Desde el menú de configuración, presiona **DOWN**
2. Usa **UP/DOWN** para ajustar el offset del sensor (0-50 cm)
3. El valor se guarda automáticamente en EEPROM
4. Presiona **LEFT** o **SELECT** para volver al menú

## ⚙️ Configuración

### Parámetros del Sistema

| Parámetro | Descripción | Rango | Valor por Defecto |
|-----------|-------------|-------|-------------------|
| **Altura Total** | Altura del tanque desde el sensor hasta el fondo | 10-400 cm | 100 cm |
| **Offset Sensor** | Distancia desde el borde del tanque hasta el sensor | 0-50 cm | 5 cm |

### Cálculo del Porcentaje de Llenado

El sistema calcula el nivel de líquido usando la fórmula:

```
Nivel de Líquido = Altura Total - (Distancia Medida - Offset Sensor)
Porcentaje = (Nivel de Líquido / Altura Total) × 100
```

### Almacenamiento en EEPROM

Los parámetros de configuración se guardan automáticamente en la EEPROM del Arduino:
- La configuración persiste al apagar el sistema
- No se requiere reconfigurar cada vez que se enciende
- Los valores se validan al cargar para evitar datos corruptos

## 🔍 Características

- ✅ Medición continua de distancia cada 500ms
- ✅ Cálculo automático del porcentaje de llenado
- ✅ Menú interactivo con botones del LCD Shield
- ✅ Configuración persistente en EEPROM
- ✅ Validación de lecturas del sensor
- ✅ Indicador visual del nivel (barra de progreso)
- ✅ Anti-rebote de botones implementado
- ✅ Manejo de errores de lectura

## 📊 Especificaciones Técnicas

- **Rango de medición**: 2-400 cm (limitado por HC-SR04)
- **Precisión**: ±0.3 cm (típica del HC-SR04)
- **Frecuencia de actualización**: 2 Hz (500ms)
- **Alimentación**: 5V (vía USB o adaptador 7-12V)
- **Consumo**: ~70mA (típico)
- **Temperatura de operación**: 0-50°C

## 🛠️ Solución de Problemas

### El LCD no muestra nada
- Verifica que el LCD Keypad Shield esté bien conectado
- Ajusta el potenciómetro de contraste en el shield
- Verifica la alimentación (debe ser 5V)

### Lecturas erráticas del sensor
- Asegúrate de que el sensor esté montado firmemente
- Verifica las conexiones TRIG y ECHO
- Evita superficies muy irregulares o con espuma
- El sensor debe apuntar perpendicular a la superficie del líquido

### Los botones no responden
- Verifica que el pin A0 esté correctamente conectado
- Prueba presionar los botones con más firmeza
- Verifica que no haya cortocircuitos en el shield

### El porcentaje es incorrecto
- Verifica la configuración de altura del tanque
- Ajusta el offset del sensor según la instalación
- Mide manualmente la altura total del tanque

## 🔄 Instalación Física

1. **Montaje del sensor**: Instala el HC-SR04 en la parte superior del tanque, apuntando hacia abajo
2. **Posición**: El sensor debe estar centrado y perpendicular a la superficie del líquido
3. **Altura**: Mide la distancia desde el sensor hasta el fondo del tanque
4. **Offset**: Mide la distancia desde el borde del tanque hasta el sensor
5. **Protección**: Si es posible, protege el sensor de salpicaduras directas

## 🤝 Contribuciones

Las contribuciones son bienvenidas. Por favor:
1. Haz un fork del proyecto
2. Crea una rama para tu feature (`git checkout -b feature/AmazingFeature`)
3. Commit tus cambios (`git commit -m 'Add some AmazingFeature'`)
4. Push a la rama (`git push origin feature/AmazingFeature`)
5. Abre un Pull Request

## 📝 Licencia

Este proyecto está bajo la Licencia MIT. Ver el archivo `LICENSE` para más detalles.

## 👤 Autor

Proyecto **controlTachoSalero** - Sistema de medición de nivel para tanques de salmuera

## 🙏 Agradecimientos

- Comunidad Arduino por las librerías y documentación
- Fabricantes de los componentes HC-SR04 y LCD Keypad Shield
- Todos los contribuidores del proyecto

---

**¿Necesitas ayuda?** Abre un [issue](https://github.com/pingitzern/controlTachoSalero/issues) en GitHub.