/*
 Titulo: Salida Digital
 Descripcion: Se usa un led para encederlo
*/

// Declaramos el pin de entrada
#define LED 23

void setup() {
  //Definimos el pin como salida
  pinMode(LED,OUTPUT);
}

void loop() {
  //Ponemos la salida en un nivel alto
  digitalWrite(LED,HIGH);
  //Pausa de 1000 milisegundos
  delay(1000);
  //Ponemos la salida en un nivel bajo
  digitalWrite(LED,LOW);
  //Pausa de 1000 milisegundos
  delay(1000);
}
