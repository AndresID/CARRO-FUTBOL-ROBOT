#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>
#include <Servo.h>  

// Pines botones

// Pines del Puente H

// Motor 1
#define IN1 8  // Motor 1 adelante
#define IN2 7  // Motor 1 atrás  
#define ENA 6  // PWM Motor 1

// Motor 2
#define IN3 4  // Motor 2 adelante
#define IN4 2  // Motor 2 atrás
#define ENB 5  // PWM Motor 2

// Pin del Servo
//#define ServoPIN 3  // PWM para el servo

// Configuración NRF24L01
RF24 radio(9, 10);  // CE, CSN
const byte direccion[6] = "00001";


struct DatosControl {
  
  bool leftx; // 
  bool rightx;
  bool downy;
  bool upy; 
  bool accservo;
  int program = 0;
};

DatosControl datosControl;
Servo miServo;  // Crear objeto servo

void setup() {
  
  Serial.begin(9600);
  
  // Configuración de los pines del motor
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(ENA, OUTPUT);

  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  pinMode(ENB, OUTPUT);

  // Configuración del servo
  miServo.attach(3);  // Conectar el servo al pin definido
  miServo.write(0);  // Iniciar el servo en la posición neutral (90 grados)

  // Inicializar el módulo NRF24L01
  radio.begin();
  if (!radio.begin()) {
    Serial.println("No se pudo Iniciar el módulo RF");
    while (1);
  }
  radio.setChannel(51);
  radio.openReadingPipe(0, direccion);
  radio.startListening();  // Comenzar a escuchar las señales del emisor
}

void loop() {
  if (radio.available()) {
    radio.read(&datosControl, sizeof(datosControl));
    
    /////////////////////////////////////////////////////////////////////////
    // PROGRAMA 0 GIRA EN SU PROPIO EJE
    if(datosControl.program == 0){

      if ( datosControl.upy == true){ //Adelante
        digitalWrite(IN1, HIGH);
        digitalWrite(IN2, LOW);
        digitalWrite(IN3, HIGH);
        digitalWrite(IN4, LOW);
        analogWrite(ENA, 255);
        analogWrite(ENB, 255);

      } 

      else if (datosControl.downy == true) { //Atrás
        digitalWrite(IN1, LOW);
        digitalWrite(IN2, HIGH);
        digitalWrite(IN3, LOW);
        digitalWrite(IN4, HIGH);
        analogWrite(ENA, 255);
        analogWrite(ENB, 255);

      } 

      else { //Stop
        digitalWrite(IN1, LOW);
        digitalWrite(IN2, LOW);
        digitalWrite(IN3, LOW);
        digitalWrite(IN4, LOW);
      
      }

      if (datosControl.rightx == true){ //Derecha
        digitalWrite(IN1, LOW);
        digitalWrite(IN2, HIGH);
        digitalWrite(IN3, HIGH);
        digitalWrite(IN4, LOW);
        analogWrite(ENA, 255);
        analogWrite(ENB, 255);

      } 

      else if (datosControl.leftx == true) { //Izquierda
        digitalWrite(IN1, HIGH);
        digitalWrite(IN2, LOW);
        digitalWrite(IN3, LOW);
        digitalWrite(IN4, HIGH);
        analogWrite(ENA, 255);
        analogWrite(ENB, 255);

      } 
        
      if (datosControl.accservo == true) {
        miServo.write(30);  // Mueve el servo a 90 grados cuando se presiona el botón
        delay(100);

      } 
      else {
        miServo.write(0);  // Mueve el servo a la posición neutral (0 grados)
      } 
    // Control del servo usando el botón del joystick
    }

    /////////////////////////////////////////////////////////////////////////
    // PROGRAMA 1 APAGA UN MOTOR
    if(datosControl.program == 1){

      if ( datosControl.rightx == true){ //Adelante
        digitalWrite(IN1, LOW);
        digitalWrite(IN2, HIGH);
        digitalWrite(IN3, HIGH);
        digitalWrite(IN4, LOW);
        analogWrite(ENA, 255);
        analogWrite(ENB, 255);

      } 

      else if (datosControl.leftx == true) { //Atrás
        digitalWrite(IN1, HIGH);
        digitalWrite(IN2, LOW);
        digitalWrite(IN3, LOW);
        digitalWrite(IN4, HIGH);
        analogWrite(ENA, 255);
        analogWrite(ENB, 255);

      } 

      else { //Stop
        digitalWrite(IN1, LOW);
        digitalWrite(IN2, LOW);
        digitalWrite(IN3, LOW);
        digitalWrite(IN4, LOW);
      
      }

      if (datosControl.upy == true){ //Derecha
        digitalWrite(IN1, HIGH);
        digitalWrite(IN2, LOW);
        digitalWrite(IN3, HIGH);
        digitalWrite(IN4, LOW);
        analogWrite(ENA, 0);
        analogWrite(ENB, 255);

      } 

      else if (datosControl.downy == true) { //Izquierda
        digitalWrite(IN1, LOW);
        digitalWrite(IN2, HIGH);
        digitalWrite(IN3, HIGH);
        digitalWrite(IN4, LOW);
        analogWrite(ENA, 255);
        analogWrite(ENB, 0);

      } 
        
      if (datosControl.accservo == true) {
        miServo.write(30);  // Mueve el servo a 90 grados cuando se presiona el botón
        delay(100);

      } 
      else {
        miServo.write(0);  // Mueve el servo a la posición neutral (0 grados)
      } 
    // Control del servo usando el botón del joystick
    }
    
    /////////////////////////////////////////////////////////////////////////
    // PROGRAMA 2 APAGA UN MOTOR
    if(datosControl.program == 2){

      if ( datosControl.rightx == true){ //Adelante
        digitalWrite(IN1, LOW);
        digitalWrite(IN2, HIGH);
        digitalWrite(IN3, HIGH);
        digitalWrite(IN4, LOW);
        analogWrite(ENA, 255);
        analogWrite(ENB, 255);

      } 

      else if (datosControl.leftx == true) { //Atrás
        digitalWrite(IN1, HIGH);
        digitalWrite(IN2, LOW);
        digitalWrite(IN3, LOW);
        digitalWrite(IN4, HIGH);
        analogWrite(ENA, 255);
        analogWrite(ENB, 255);

      } 

      else { //Stop
        digitalWrite(IN1, LOW);
        digitalWrite(IN2, LOW);
        digitalWrite(IN3, LOW);
        digitalWrite(IN4, LOW);
      
      }

      if (datosControl.upy == true){ //Derecha
        digitalWrite(IN1, LOW);
        digitalWrite(IN2, HIGH);
        digitalWrite(IN3, HIGH);
        digitalWrite(IN4, LOW);
        analogWrite(ENA, 45);
        analogWrite(ENB, 255);

      } 

      else if (datosControl.downy == true) { //Izquierda
        digitalWrite(IN1, LOW);
        digitalWrite(IN2, HIGH);
        digitalWrite(IN3, HIGH);
        digitalWrite(IN4, LOW);
        analogWrite(ENA, 255);
        analogWrite(ENB, 45);

      } 
        
      if (datosControl.accservo == true) {
        miServo.write(30);  // Mueve el servo a 90 grados cuando se presiona el botón
        delay(100);

      } 
      else {
        miServo.write(0);  // Mueve el servo a la posición neutral (0 grados)
      } 
      // Control del servo usando el botón del joystick
    }
        
  }
}