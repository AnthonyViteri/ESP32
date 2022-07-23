/*
 Titulo: Entrada Digital con pulsador
 Descripcion: Se usa una resistencia en PullDown interna 
*/

// Declaramos el pin de entrada
#define PIN 23

//Variables para lectura 
int value_estate = 0;

void setup() {
  //Inicializamos el perto serial
  Serial.begin(9600);

  //Definimos el pin como modo de entrada con PullDown
  pinMode(PIN,INPUT_PULLDOWN);
}

void loop() {
  //Leemos el valor digital del pin
  value_estate = digitalRead(PIN);

  //Ponemos la condicion:
  if(value_estate == HIGH){
    Serial.println("Pulsado!");
  }
  //Pausa de 100 milisegundos
  delay(100);
}
