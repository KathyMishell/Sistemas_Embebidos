/* DEBER N 3.1
* NOMBRE:Katherine Guatemal
* TEMA: Comunicación I2C
* GUÍA: Mediante comunicación I2C configurar 1 maestro y 3 esclavos. Cada esclavo tendrá conectados 3 leds en sus salidas digitales.
*       Los cuales deberán encenderse de forma síncrona   y ordenada. 
*       Los leds del primer esclavo deberán entran en funcionamiento cuando se ingrese 'Cualquier caracter'.
*       Luego cuando se ingrese otro 'Cualquier caracter 2' entrará en funcionamiento el esclavo 2
*       Y después cuando se ingrese otro 'Cualquier caracter 3' entrará en funcionamiento el esclavo 3.
*/

////////////////////////////////////////////////////////////ESCLAVO Nº 1//////////////////////////////////////////////////

#include <Wire.h>                                                           //librería I2C
char dato;                                                                  //Variable de alacenamiento de datos
const int led4=8;                                                           //Led 1 en Pin 8
const int led5=9;                                                           //Led 2 en Pin 9
const int led6=10;                                                          //Led 3 en Pin 10


void setup() {
 Wire.begin(5);                                                             //Inicia la comunicación I2C y id de esclavo
 Serial.begin(9600);                                                        //Inicia la comunicación serial  
 Wire.onReceive(receiveEvent);                                              //Evento de Recepción
 pinMode(led4,OUTPUT);                                                      //Asigno el Pin 8 como salida
 pinMode(led5,OUTPUT);                                                      //Asigno el Pin 9 como salida
 pinMode(led6,OUTPUT);                                                      //Asigno el Pin 10 como salida
 
}

void loop() {

}

void receiveEvent(int bytes){                                               //Creación de un nuevo evento
while(Wire.available()){                                                    //Condición de ingreso de caracter
  dato=Wire.read();                                                         //Asignación del caracter ingreso a la Variable dato
  switch(dato){                                                             
      case '2':                                                             //Caso 1
        digitalWrite(led4,HIGH);                                            //Manda 5V al led 4
        delay(20500);                                                       //Tiempo      
        digitalWrite(led4,LOW);                                             //Manda 0V al led 4
        delay(9500);       
        digitalWrite(led5,HIGH);                                            //Manda 5V al led 5
        delay(20500); 
        digitalWrite(led5,LOW);                                             //Manda 0V al led 5
        delay(9500); 
        digitalWrite(led6,HIGH);                                            //Manda 5V al led 6
        delay(20500);   
        digitalWrite(led6,LOW);                                             //Manda 0V al led 6
        delay(9500); 
    break;
  }
}  
}
