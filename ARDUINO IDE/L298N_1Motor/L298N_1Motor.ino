/*
 Titulo: L298N control de un motor
 Descripción: Usamos la libreria de L298N para ESP32 para el 
 control de 1 motor
 */

//Incluimos libreria del L398N
#include <Robojax_L298N_DC_motor.h>

// Configuración del motor 1
#define CHA 0
#define ENA 13 // Este pin debe tener habilitado el uso de PWM
#define IN1 12 
#define IN2 14

//Constantes para controlar la dirección de los motores
const int CCW = 2; // NO MODIFICAR
const int CW  = 1; // NO MODIFICAR

#define motor1 1 // NO CAMBIAR

//Creamos la instancia:
Robojax_L298N_DC_motor motor(IN1, IN2, ENA, CHA, true);  
 
void setup() {
  Serial.begin(115200);
  motor.begin();
}

void loop() {
  motor.rotate(motor1, 60, CW);//El motor gira al 60% de us velocidad en direccion de las manecillas del reloj
  delay(3000);
  motor.brake(1); //Detenemos el motor
  delay(2000);
  motor.rotate(motor1, 100, CCW);//El motor gira al 100% de us velocidad en direccion contrario de las manecillas del reloj
  delay(3000);
  motor.brake(1);
  delay(2000);  
  for(int i=0; i<=100; i++)
  {
    motor.rotate(motor1, i, CW);
    delay(100);
  }
  delay(2000);
  motor.brake(1);
  delay(2000); 
  for(int i=0; i<=100; i++)
  {
    motor.rotate(motor1, i, CCW);
    delay(100);
  }
  motor.brake(1);
  delay(2000);  
}
