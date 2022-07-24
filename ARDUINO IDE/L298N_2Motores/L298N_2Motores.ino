/*
 Titulo: L298N control de dos motores
 Descripción: Usamos la libreria de L298N para ESP32 para el 
 control de 2 motores
 */

//Incluimos libreria del L398N
#include <Robojax_L298N_DC_motor.h>

// Configuración del motor 1
#define CHA 0
#define ENA 13 // Este pin debe tener habilitado el uso de PWM
#define IN1 12 
#define IN2 14
// Configuración del motor 2
#define IN3 27
#define IN4 26
#define ENB 25 // Este pin debe tener habilitado el uso de PWM
#define CHB 1


//Constantes para controlar la dirección de los motores
const int CCW = 2; // NO MODIFICAR
const int CW  = 1; // NO MODIFICAR

#define motor1 1 // NO CAMBIAR
#define motor2 2 // NO CAMBIAR

//Creamos la instancia:
// Para dos motores sin información de depuración 
//Robojax_L298N_DC_motor robot(IN1, IN2, ENA, CHA,  IN3, IN4, ENB, CHB);

// Para dos motores sin información de depuración
Robojax_L298N_DC_motor robot(IN1, IN2, ENA, CHA, IN3, IN4, ENB, CHB, true);
 
void setup() {
  Serial.begin(115200);
  robot.begin();
}

void loop() {
  robot.rotate(motor1, 80, CW);
  robot.rotate(motor2, 70, CCW);
  
  delay(3000);

  robot.brake(1);
  robot.brake(2);  
  delay(2000);


  robot.rotate(motor1, 100, CW);
  delay(3000);
  
  robot.rotate(motor2, 100, CCW);
  
  robot.brake(1);
  robot.brake(2);   
  delay(2000);  

  for(int i=0; i<=100; i++)
  {
    robot.rotate(motor1, i, CW); 
    delay(100);
  }
  delay(2000);
  
  robot.brake(1);
  delay(2000);  
  
  for(int i=0; i<=100; i++)
  {
    robot.rotate(motor2, i, CW);
    delay(100);
  }
  delay(2000);
  
  robot.brake(2);
  delay(2000);    
}
