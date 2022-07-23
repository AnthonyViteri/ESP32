/*
 Titulo: PWM para ESP32-Wroom32 para multiples salidas
 Descripción: Programa para el uso de PWM
 en la ESP32 con arduino para varias salidas
 */

// Propiedades para el PWM
const int frecuencia = 5000; // Soporta : 1 a 40000 kHz
const int canal_1 = 0; // Canales disponibles: 0 al 15
const int canal_2 = 1; // Canales disponibles: 0 al 15
const int resolucion = 8; // Resolucion : 1 a 16 bits

// Pines
#define LED1 23
#define LED2 13

void setup() {
  //configuramos el PWM
  ledcSetup(canal_1,frecuencia,resolucion);
  ledcSetup(canal_2,frecuencia,resolucion);
  
  //Asociamos el canal al GPIO
  ledcAttachPin(LED1,canal_1);
  ledcAttachPin(LED2,canal_2);
}

void loop() {
  //Incrementamos el brillo
  for(int i =0;i<=255;i++){
    ledcWrite(canal_1,i);
    ledcWrite(canal_2,255-i);
    delay(10);
  }
  //Decrementamos el brillo
  for(int i =255;i>=0;i--){
    ledcWrite(canal_1,i);
    ledcWrite(canal_2,255-i);
    delay(10);
  }
}
