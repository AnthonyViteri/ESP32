/*
 Titulo: PWM para ESP32-Wroom32
 Descripción: Programa para el uso de PWM
 en la ESP32 con arduino
 */

// Propiedades para el PWM
const int frecuencia = 5000; // Soporta : 1 a 40000 kHz
const int canal = 0; // Canales disponibles: 0 al 15
const int resolucion = 8; // Resolucion : 1 a 16 bits

// Pines
#define LED 23

void setup() {
  //configuramos el PWM
  ledcSetup(canal,frecuencia,resolucion);
  
  //Asociamos el canal al GPIO
  ledcAttachPin(LED,canal);
}

void loop() {
  //Incrementamos el brillo
  for(int i =0;i<=255;i++){
    ledcWrite(canal,i);
    delay(10);
  }
  //Decrementamos el brillo
  for(int i =255;i>=0;i--){
    ledcWrite(canal,i);
    delay(10);
  }
}
