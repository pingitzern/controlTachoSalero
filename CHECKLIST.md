# Lista de Verificación - controlTachoSalero

## ✅ Checklist de Instalación

### Antes de Empezar
- [ ] Arduino UNO disponible
- [ ] LCD Keypad Shield 16x2 disponible
- [ ] Sensor HC-SR04 disponible
- [ ] Cables de conexión disponibles
- [ ] Fuente de alimentación (USB o 7-12V DC)
- [ ] Arduino IDE instalado en el computador
- [ ] Cable USB tipo B (para Arduino UNO)

### Paso 1: Hardware
- [ ] LCD Keypad Shield montado correctamente en Arduino UNO
- [ ] Todos los pines del shield bien conectados
- [ ] Sensor HC-SR04 VCC conectado a 5V
- [ ] Sensor HC-SR04 GND conectado a GND
- [ ] Sensor HC-SR04 TRIG conectado a D2
- [ ] Sensor HC-SR04 ECHO conectado a D3
- [ ] Todas las conexiones firmes y seguras

### Paso 2: Software
- [ ] Código descargado del repositorio
- [ ] Archivo controlTachoSalero.ino abierto en Arduino IDE
- [ ] Placa correcta seleccionada (Tools > Board > Arduino UNO)
- [ ] Puerto correcto seleccionado (Tools > Port)
- [ ] Código cargado exitosamente (sin errores de compilación)
- [ ] Código subido al Arduino (Upload completado)

### Paso 3: Primera Puesta en Marcha
- [ ] Mensaje de bienvenida visible en LCD
- [ ] LCD muestra "ControlTacho" en línea 1 y "Salero v1.0" en línea 2
- [ ] Después de 2 segundos, cambia a pantalla principal
- [ ] Pantalla principal muestra "Dist:" y "Nivel:"
- [ ] Los valores cambian cuando mueves objetos frente al sensor

### Paso 4: Prueba de Botones
- [ ] Botón SELECT abre el menú de configuración
- [ ] Botón UP funciona en los menús
- [ ] Botón DOWN funciona en los menús
- [ ] Botón LEFT vuelve al menú anterior
- [ ] Potenciómetro del LCD ajusta el contraste correctamente

### Paso 5: Prueba de Sensor
- [ ] Sensor responde a objetos a 5-10 cm
- [ ] Sensor responde a objetos a 50 cm
- [ ] Sensor responde a objetos a 100 cm
- [ ] Lecturas son estables (no saltan erráticamente)
- [ ] Mensaje de "Error lectura" no aparece constantemente

### Paso 6: Configuración
- [ ] Altura total del tanque medida con cinta métrica
- [ ] Offset del sensor medido con cinta métrica
- [ ] Altura total configurada en el menú
- [ ] Offset configurado en el menú
- [ ] Valores se guardan al salir del menú
- [ ] Valores persisten después de desconectar/reconectar

### Paso 7: Calibración
- [ ] Con tanque vacío, porcentaje muestra cerca de 0%
- [ ] Con tanque medio, porcentaje muestra cerca de 50%
- [ ] Con tanque lleno, porcentaje muestra cerca de 100%
- [ ] Ajustes realizados si es necesario
- [ ] Calibración documentada

### Paso 8: Instalación Final
- [ ] Sensor montado firmemente en posición final
- [ ] Sensor apuntando perpendicular al líquido
- [ ] Cables asegurados para evitar desconexiones
- [ ] Sistema protegido de salpicaduras
- [ ] Arduino protegido en caja o gabinete
- [ ] Alimentación conectada y estable
- [ ] Lecturas verificadas en condiciones reales

## 🔧 Checklist de Solución de Problemas

### Si el LCD no muestra nada:
- [ ] Verificar que el shield esté bien conectado
- [ ] Ajustar potenciómetro de contraste
- [ ] Verificar alimentación (debe ser 5V)
- [ ] Probar cargar un sketch de ejemplo de LCD
- [ ] Verificar que los pines estén correctos en el código

### Si el sensor no funciona:
- [ ] Verificar conexión VCC a 5V
- [ ] Verificar conexión GND a GND
- [ ] Verificar conexión TRIG a D2
- [ ] Verificar conexión ECHO a D3
- [ ] Probar con código de ejemplo simple del sensor
- [ ] Verificar que el sensor no esté obstruido
- [ ] Medir voltaje en VCC del sensor (debe ser ~5V)

### Si los botones no responden:
- [ ] Verificar que el shield esté bien asentado
- [ ] Verificar conexión del pin A0
- [ ] Probar cada botón individualmente
- [ ] Limpiar los botones con alcohol isopropílico
- [ ] Verificar valores ADC con código de prueba

### Si el porcentaje es incorrecto:
- [ ] Verificar configuración de altura total
- [ ] Verificar configuración de offset
- [ ] Re-medir altura del tanque físicamente
- [ ] Re-medir offset del sensor físicamente
- [ ] Verificar que el sensor esté perpendicular
- [ ] Re-calibrar el sistema

### Si las lecturas son inestables:
- [ ] Verificar que el sensor esté firme
- [ ] Verificar que los cables no estén flojos
- [ ] Alejar de fuentes de interferencia
- [ ] Verificar que la superficie no tenga espuma
- [ ] Esperar a que el líquido se estabilice
- [ ] Aumentar el tiempo de lectura

## 📝 Checklist de Mantenimiento

### Mantenimiento Semanal:
- [ ] Verificar que el sistema esté funcionando
- [ ] Verificar que las lecturas sean correctas
- [ ] Verificar que no haya mensajes de error

### Mantenimiento Mensual:
- [ ] Limpiar sensor con paño seco
- [ ] Verificar todas las conexiones
- [ ] Verificar legibilidad del LCD
- [ ] Probar todos los botones
- [ ] Verificar que el sistema esté bien montado

### Mantenimiento Trimestral:
- [ ] Verificar calibración con medición manual
- [ ] Limpiar LCD y ajustar contraste
- [ ] Inspeccionar cables por desgaste
- [ ] Verificar firmeza del montaje del sensor
- [ ] Documentar cualquier cambio o problema

### Mantenimiento Anual:
- [ ] Revisión completa del sistema
- [ ] Reemplazar cables si muestran desgaste
- [ ] Limpiar polvo de todos los componentes
- [ ] Verificar conexiones soldadas (si aplica)
- [ ] Re-calibrar completamente el sistema
- [ ] Actualizar documentación

## 🚨 Checklist de Emergencia

### Si el sistema deja de funcionar:
- [ ] Verificar alimentación
- [ ] Verificar que el Arduino esté encendido (LED ON)
- [ ] Desconectar y reconectar alimentación
- [ ] Verificar todas las conexiones
- [ ] Re-cargar el código si es necesario
- [ ] Verificar con multímetro si hay voltajes correctos
- [ ] Contactar soporte si el problema persiste

### Si el sensor da lecturas erróneas:
- [ ] Limpiar el sensor
- [ ] Verificar que no esté obstruido
- [ ] Verificar montaje y alineación
- [ ] Desconectar y reconectar el sensor
- [ ] Probar con código de prueba del sensor
- [ ] Reemplazar el sensor si está defectuoso

### Si se perdió la configuración:
- [ ] Volver a configurar altura total
- [ ] Volver a configurar offset
- [ ] Verificar que se guarde correctamente
- [ ] Si el problema persiste, revisar código EEPROM

## 📊 Checklist de Documentación

### Documentación de Instalación:
- [ ] Fecha de instalación registrada
- [ ] Ubicación del tanque documentada
- [ ] Altura total medida y documentada
- [ ] Offset medido y documentado
- [ ] Fotos del montaje tomadas
- [ ] Diagrama de conexiones verificado

### Documentación de Calibración:
- [ ] Fecha de calibración registrada
- [ ] Valores de configuración documentados
- [ ] Verificaciones realizadas y documentadas
- [ ] Cualquier ajuste documentado
- [ ] Próxima fecha de calibración programada

### Documentación de Mantenimiento:
- [ ] Registro de mantenimiento iniciado
- [ ] Cada mantenimiento documentado
- [ ] Problemas encontrados documentados
- [ ] Soluciones aplicadas documentadas
- [ ] Próximo mantenimiento programado

---

**Versión del documento**: 1.0  
**Última actualización**: 2025-10-25
