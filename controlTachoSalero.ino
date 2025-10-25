/*
 * controlTachoSalero - Medidor de nivel de salmuera
 * 
 * Hardware:
 * - Arduino UNO
 * - LCD Keypad Shield 16x2
 * - Sensor ultrasónico HC-SR04
 * 
 * Funcionalidad:
 * - Mide distancia con sensor ultrasónico
 * - Calcula porcentaje de llenado del tanque
 * - Menú con botones para ajustar altura del tanque y offset del sensor
 * - Configuración guardada en EEPROM
 * 
 * Autor: controlTachoSalero Project
 * Licencia: MIT
 */

#include <LiquidCrystal.h>
#include <EEPROM.h>

// Pines del LCD Keypad Shield
LiquidCrystal lcd(8, 9, 4, 5, 6, 7);

// Pines del sensor HC-SR04
#define TRIG_PIN 2
#define ECHO_PIN 3

// Definición de botones del LCD Keypad Shield
#define btnRIGHT  0
#define btnUP     1
#define btnDOWN   2
#define btnLEFT   3
#define btnSELECT 4
#define btnNONE   5

// Direcciones EEPROM
#define EEPROM_ALTURA_ADDR 0    // 2 bytes para int
#define EEPROM_OFFSET_ADDR 2    // 2 bytes para int
#define EEPROM_INIT_ADDR 4      // 1 byte para marca de inicialización

// Valores por defecto
#define DEFAULT_ALTURA 100      // Altura del tanque en cm
#define DEFAULT_OFFSET 5        // Offset del sensor en cm
#define EEPROM_INIT_VALUE 42    // Valor mágico para verificar inicialización

// Variables de configuración
int alturaTotal = DEFAULT_ALTURA;
int offsetSensor = DEFAULT_OFFSET;

// Variables del menú
enum MenuState {
  MENU_MAIN,
  MENU_CONFIG,
  MENU_ALTURA,
  MENU_OFFSET
};

MenuState menuActual = MENU_MAIN;
unsigned long ultimaLectura = 0;
unsigned long ultimoPulso = 0;
const unsigned long INTERVALO_LECTURA = 500;  // Leer cada 500ms
const unsigned long DEBOUNCE_DELAY = 200;     // Anti-rebote de botones

// Variables de medición
float distancia = 0;
int porcentaje = 0;

void setup() {
  // Configurar LCD
  lcd.begin(16, 2);
  
  // Configurar pines del sensor
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
  
  // Cargar configuración de EEPROM
  cargarConfiguracion();
  
  // Mensaje de bienvenida
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("ControlTacho");
  lcd.setCursor(0, 1);
  lcd.print("Salero v1.0");
  delay(2000);
  
  lcd.clear();
}

void loop() {
  unsigned long tiempoActual = millis();
  
  // Leer sensor periódicamente
  if (tiempoActual - ultimaLectura >= INTERVALO_LECTURA) {
    ultimaLectura = tiempoActual;
    distancia = medirDistancia();
    porcentaje = calcularPorcentaje(distancia);
  }
  
  // Leer botones
  int boton = leerBoton();
  
  // Procesar según el menú actual
  if (boton != btnNONE && (tiempoActual - ultimoPulso > DEBOUNCE_DELAY)) {
    ultimoPulso = tiempoActual;
    procesarBoton(boton);
  }
  
  // Actualizar pantalla
  actualizarPantalla();
  
  delay(100);
}

/**
 * Lee el sensor ultrasónico HC-SR04
 * Retorna la distancia en centímetros
 */
float medirDistancia() {
  // Pulso de trigger
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);
  
  // Leer el pulso de echo
  long duracion = pulseIn(ECHO_PIN, HIGH, 30000); // Timeout 30ms
  
  // Calcular distancia (velocidad del sonido = 343 m/s = 0.0343 cm/us)
  // Distancia = (tiempo * velocidad) / 2
  float dist = duracion * 0.0343 / 2;
  
  // Validar lectura
  if (dist < 2 || dist > 400) {
    return -1; // Lectura inválida
  }
  
  return dist;
}

/**
 * Calcula el porcentaje de llenado del tanque
 */
int calcularPorcentaje(float dist) {
  if (dist < 0) {
    return -1; // Error de lectura
  }
  
  // Calcular nivel de líquido
  // Nivel = AlturaTotal - (Distancia - Offset)
  float nivelLiquido = alturaTotal - (dist - offsetSensor);
  
  // Calcular porcentaje
  int pct = (int)((nivelLiquido / alturaTotal) * 100);
  
  // Limitar entre 0 y 100
  if (pct < 0) pct = 0;
  if (pct > 100) pct = 100;
  
  return pct;
}

/**
 * Lee el botón pulsado del LCD Keypad Shield
 */
int leerBoton() {
  int adc_key_in = analogRead(0);
  
  // Valores típicos del LCD Keypad Shield
  if (adc_key_in > 1000) return btnNONE;
  if (adc_key_in < 50)   return btnRIGHT;
  if (adc_key_in < 195)  return btnUP;
  if (adc_key_in < 380)  return btnDOWN;
  if (adc_key_in < 555)  return btnLEFT;
  if (adc_key_in < 790)  return btnSELECT;
  
  return btnNONE;
}

/**
 * Procesa la pulsación de botones según el menú actual
 */
void procesarBoton(int boton) {
  switch (menuActual) {
    case MENU_MAIN:
      if (boton == btnSELECT) {
        menuActual = MENU_CONFIG;
        lcd.clear();
      }
      break;
      
    case MENU_CONFIG:
      if (boton == btnUP) {
        menuActual = MENU_ALTURA;
        lcd.clear();
      } else if (boton == btnDOWN) {
        menuActual = MENU_OFFSET;
        lcd.clear();
      } else if (boton == btnLEFT || boton == btnSELECT) {
        menuActual = MENU_MAIN;
        lcd.clear();
      }
      break;
      
    case MENU_ALTURA:
      if (boton == btnUP) {
        alturaTotal += 5;
        if (alturaTotal > 400) alturaTotal = 400;
        guardarConfiguracion();
      } else if (boton == btnDOWN) {
        alturaTotal -= 5;
        if (alturaTotal < 10) alturaTotal = 10;
        guardarConfiguracion();
      } else if (boton == btnLEFT || boton == btnSELECT) {
        menuActual = MENU_CONFIG;
        lcd.clear();
      }
      break;
      
    case MENU_OFFSET:
      if (boton == btnUP) {
        offsetSensor += 1;
        if (offsetSensor > 50) offsetSensor = 50;
        guardarConfiguracion();
      } else if (boton == btnDOWN) {
        offsetSensor -= 1;
        if (offsetSensor < 0) offsetSensor = 0;
        guardarConfiguracion();
      } else if (boton == btnLEFT || boton == btnSELECT) {
        menuActual = MENU_CONFIG;
        lcd.clear();
      }
      break;
  }
}

/**
 * Actualiza la pantalla LCD según el menú actual
 */
void actualizarPantalla() {
  switch (menuActual) {
    case MENU_MAIN:
      mostrarPantallaMain();
      break;
    case MENU_CONFIG:
      mostrarPantallaConfig();
      break;
    case MENU_ALTURA:
      mostrarPantallaAltura();
      break;
    case MENU_OFFSET:
      mostrarPantallaOffset();
      break;
  }
}

/**
 * Pantalla principal - Muestra distancia y porcentaje
 */
void mostrarPantallaMain() {
  lcd.setCursor(0, 0);
  
  if (distancia < 0) {
    lcd.print("Error lectura   ");
  } else {
    lcd.print("Dist: ");
    lcd.print(distancia, 1);
    lcd.print(" cm   ");
  }
  
  lcd.setCursor(0, 1);
  
  if (porcentaje < 0) {
    lcd.print("Nivel: ---%     ");
  } else {
    lcd.print("Nivel: ");
    lcd.print(porcentaje);
    lcd.print("%      ");
    
    // Barra de progreso simple
    lcd.setCursor(13, 1);
    if (porcentaje < 25) {
      lcd.print("   ");
    } else if (porcentaje < 50) {
      lcd.print("*  ");
    } else if (porcentaje < 75) {
      lcd.print("** ");
    } else {
      lcd.print("***");
    }
  }
}

/**
 * Pantalla de configuración - Menú principal
 */
void mostrarPantallaConfig() {
  lcd.setCursor(0, 0);
  lcd.print("CONFIGURACION   ");
  lcd.setCursor(0, 1);
  lcd.print("UP/DOWN p/elegir");
}

/**
 * Pantalla de ajuste de altura del tanque
 */
void mostrarPantallaAltura() {
  lcd.setCursor(0, 0);
  lcd.print("Altura Tanque   ");
  lcd.setCursor(0, 1);
  lcd.print(alturaTotal);
  lcd.print(" cm (UP/DOWN)");
  
  // Limpiar caracteres extras
  if (alturaTotal < 100) {
    lcd.setCursor(3, 1);
    lcd.print(" ");
  }
}

/**
 * Pantalla de ajuste de offset del sensor
 */
void mostrarPantallaOffset() {
  lcd.setCursor(0, 0);
  lcd.print("Offset Sensor   ");
  lcd.setCursor(0, 1);
  lcd.print(offsetSensor);
  lcd.print(" cm (UP/DOWN)");
  
  // Limpiar caracteres extras
  if (offsetSensor < 10) {
    lcd.setCursor(2, 1);
    lcd.print(" ");
  }
}

/**
 * Carga la configuración desde EEPROM
 */
void cargarConfiguracion() {
  // Verificar si EEPROM está inicializada
  byte initFlag = EEPROM.read(EEPROM_INIT_ADDR);
  
  if (initFlag == EEPROM_INIT_VALUE) {
    // EEPROM inicializada, cargar valores
    EEPROM.get(EEPROM_ALTURA_ADDR, alturaTotal);
    EEPROM.get(EEPROM_OFFSET_ADDR, offsetSensor);
    
    // Validar valores cargados
    if (alturaTotal < 10 || alturaTotal > 400) {
      alturaTotal = DEFAULT_ALTURA;
    }
    if (offsetSensor < 0 || offsetSensor > 50) {
      offsetSensor = DEFAULT_OFFSET;
    }
  } else {
    // Primera vez, usar valores por defecto y guardar
    alturaTotal = DEFAULT_ALTURA;
    offsetSensor = DEFAULT_OFFSET;
    guardarConfiguracion();
  }
}

/**
 * Guarda la configuración en EEPROM
 */
void guardarConfiguracion() {
  EEPROM.put(EEPROM_ALTURA_ADDR, alturaTotal);
  EEPROM.put(EEPROM_OFFSET_ADDR, offsetSensor);
  EEPROM.write(EEPROM_INIT_ADDR, EEPROM_INIT_VALUE);
}
