/*
 * CAPÍTULO II: PUERTOS DIGITALES
 * CÓDIGO 1: Manejo de puertos configurados como salidas
 * OBJETIVO: Encender y apagar leds mediante el uso de diferentes tipos de variables
 * NOMBRE:Katherine Guatemal
 */
 //variables: númericas enteras (int), decimales (float), caracteres (chart)

#define led1 8          //uso de #define, es una variable que no se puede alterar su valor, no existe depuraciones
int led2 = 9   ;        // se puede considerar como una veriable normal, no es muy recomendable
const int led3 = 10  ;  // variable constante, es la recomendable
 
void setup() {
  pinMode(led1,OUTPUT); //declaro el pin 8 como salida
  pinMode(led2,OUTPUT); // declaro el pin 9 como salida
  pinMode(led3,OUTPUT); //declaro el pin 10 como salida
}

void loop() {
  digitalWrite(led1,HIGH);  //Envía 5V al pin8
  delay(500);               //Se detiene el microcontrolador por medio segundo
  digitalWrite(led1,LOW);   //Envía 0V al pin8
  delay(500);               //Se detiene el microcontrolador por medio segundo
  digitalWrite(led2,HIGH);  //Envía 5V al pin9
  digitalWrite(led3,LOW);   //Envía 0V al pin10
  delay(400);               //Se detiene el microcontrolador
  digitalWrite(led3,HIGH);  //Envía 5V al pin10
  digitalWrite(led2,LOW);   //Envía 0V al pin9
  delay(400);               //Se detiene el microcontrolador
}
