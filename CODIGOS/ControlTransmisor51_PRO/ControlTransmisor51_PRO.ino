#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>
#include <Servo.h>

// Pines del joystick
#define up     3 // Botón adelante
#define right  2 // Botón derecha
#define down   5 // Botón abajo
#define left   4 // Botón izquierda
#define buttonservo 8

int buttonPressCount1 = 0;
int buttonPressCount2 = 0;
int buttonPressCount3 = 0;

unsigned long lastPressTime1 = 0;
unsigned long lastPressTime2 = 0;
unsigned long lastPressTime3 = 0;
const unsigned long resetDelay = 500; 

bool buttonPressed1 = false;
bool buttonPressed2 = false;  
bool buttonPressed3 = false;   

const int buttonPin1 = 3;            // Pin donde está conectado el botón
const int buttonPin2 = 5;            // Pin donde está conectado el botón
const int buttonPin3 = 4;            // Pin donde está conectado el botón

// Configuración NRF24L01
RF24 radio(9, 10);  // CE, CSN
const byte direccion[6] = "00001";  // Dirección para el canal de comunicación

// Estructura de los datos que se enviarán
struct DatosControl {
  bool leftx; 
  bool rightx;
  bool downy;
  bool upy; 
  bool accservo;
  int program = 0;
};
DatosControl datosControl;

void setup() {
  Serial.begin(9600);
  pinMode(up, INPUT_PULLUP);
  pinMode(right, INPUT_PULLUP);
  pinMode(down, INPUT_PULLUP);
  pinMode(left, INPUT_PULLUP);
  pinMode(buttonservo, INPUT);

  radio.begin();
  if (!radio.begin()) {
    while (1); // Mantener en bucle si el módulo no se inicializa
  }

  // Configurar la dirección de escritura para el NRF24L01
  radio.setChannel(51);
  radio.openWritingPipe(direccion);
  radio.setPALevel(RF24_PA_MIN); // Establecer el nivel de potencia de la señal
  radio.stopListening();
}

void loop() {
  int buttonState1 = digitalRead(buttonPin1); // Lee el estado del botón
  int buttonState2 = digitalRead(buttonPin2); // Lee el estado del botón
  int buttonState3 = digitalRead(buttonPin3); // Lee el estado del botón

  datosControl.upy = !digitalRead(up);
  datosControl.rightx = !digitalRead(right);
  datosControl.downy = !digitalRead(down);
  datosControl.leftx = !digitalRead(left);
  datosControl.accservo = !digitalRead(buttonservo);

  /////////////////////////////////////////////////////////////////////////////////////////////

  // Manejando el primer botón
  if (buttonState1 == HIGH && !buttonPressed1) {
    buttonPressCount1++;
    lastPressTime1 = millis(); // Actualiza el tiempo de la última pulsación
    buttonPressed1 = true;      // Marca que el botón está presionado
  } 
  else if (buttonState1 == LOW) {
    buttonPressed1 = false;     // Marca que el botón está suelto
  }
  
  /////////////////////////////////////////////////////////////////////////////////////////////

  // Manejando el segundo botón
  if (buttonState2 == HIGH && !buttonPressed2) {
    buttonPressCount2++;
    lastPressTime2 = millis(); // Actualiza el tiempo de la última pulsación
    buttonPressed2 = true;      // Marca que el botón está presionado
  } 
  else if (buttonState2 == LOW) {
    buttonPressed2 = false;     // Marca que el botón está suelto
  }
  
  /////////////////////////////////////////////////////////////////////////////////////////////

  // Manejando el tercer botón
  if (buttonState3 == HIGH && !buttonPressed3) {
    buttonPressCount3++;
    lastPressTime3 = millis(); // Actualiza el tiempo de la última pulsación
    buttonPressed3 = true;      // Marca que el botón está presionado
  } 
  else if (buttonState3 == LOW) {
    buttonPressed3 = false;     // Marca que el botón está suelto
  }

  // Verificación de tiempo de reseteo para el primer botón
  if (millis() - lastPressTime1 >= resetDelay) {
    buttonPressCount1 = 0; // Resetea el contador
  }
  
  // Comprueba si se ha alcanzado el límite de pulsos para el primer botón
  if (buttonPressCount1 >= 3) {
    datosControl.program = 1;
    buttonPressCount1 = 0; // Resetea el contador
  }

  // Verificación de tiempo de reseteo para el segundo botón
  if (millis() - lastPressTime2 >= resetDelay) { // pin 2 arriba
    buttonPressCount2 = 0; // Resetea el contador
  }
  
  // Comprueba si se ha alcanzado el límite de pulsos para el segundo botón
  if (buttonPressCount2 >= 3) { // pin 3 derecha
    datosControl.program = 2;
    buttonPressCount2 = 0; // Resetea el contador
  }

  // Verificación de tiempo de reseteo para el tercer botón
  if (millis() - lastPressTime3 >= resetDelay) { 
    buttonPressCount3 = 0; // Resetea el contador
  }
  
  // Comprueba si se ha alcanzado el límite de pulsos para el tercer botón
  if (buttonPressCount3 >= 3) { // pin 4 abajo
    datosControl.program = 0;
    buttonPressCount3 = 0; // Resetea el contador
  }

  // Enviar los datos a través del módulo NRF24L01
  radio.write(&datosControl, sizeof(datosControl));

  Serial.println(datosControl.program);
  // Retardo para evitar sobrecarga de datos
  delay(50);
}