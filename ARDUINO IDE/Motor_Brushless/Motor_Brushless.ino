/*
 Titulo: Control de motor Brushless
 Descripcion: Usamos la libreria Servo para 
 controlar el motor Brushless
 */

//Incluimos libreria
#include <Servo_ESP32.h>

//Creamos instancia del ESC: Controlador de Brushless
Servo_ESP32 ESC;

//PIN DE CONTROL
#define ARMA 5

void setup() {
  Serial.begin(115200);
  ESC.attach(ARMA);//Asignamos a la instancia el PIN
  ESC.writeMicroseconds(2000);// Lo activamos con un pulso de 1 ms
  delay(5000);
}

void loop() {
  Serial.println("Velcidad 0");
  ESC.write(20); //Escribimos la velocidad para esto el rango va de 0 a 180
  delay(5000);
  Serial.println("Velcidad 120");
  ESC.write(100);
  delay(5000);
}
