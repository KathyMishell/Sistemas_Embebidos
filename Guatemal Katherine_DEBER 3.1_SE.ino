/* DEBER N 3.1
* NOMBRE:Katherine Guatemal
* TEMA: Comunicación I2C
* GUÍA: Mediante comunicación I2C configurar 1 maestro y 3 esclavos. Cada esclavo tendrá conectados 3 leds en sus salidas digitales.
*       Los cuales deberán encenderse de forma síncrona   y ordenada. 
*       Los leds del primer esclavo deberán entran en funcionamiento cuando se ingrese 'Cualquier caracter'.
*       Luego cuando se ingrese otro 'Cualquier caracter 2' entrará en funcionamiento el esclavo 2
*       Y después cuando se ingrese otro 'Cualquier caracter 3' entrará en funcionamiento el esclavo 3.
*/

////////////////////////////////////////////////////////////MASTER//////////////////////////////////////////////////

#include <Wire.h>                                                           //librería I2C
char dato;                                                                  //Variable de alacenamiento de datos

void setup() {
 Wire.begin();                                                              //Inicia la comunicación I2C
 Serial.begin(9600);                                                        //Inicia la comunicación serial


}

void loop() {
 if(Serial.available()>0){                                                  //Verifica que existan datos
   dato=Serial.read();                                                      //Almacena el dato en la variable
   switch(dato){
     case '1':
        Wire.beginTransmission(4);                                               //Empieza la comunicación I2C
        Wire.write(dato);                                                        //Envió dato
        Wire.endTransmission();                                                  //Termina la comunicación I2C
     break;
     case '2':
      Wire.beginTransmission(5);                                               //Empieza la comunicación I2C
      Wire.write(dato);                                                        //Envió dato
      Wire.endTransmission();                                                  //Termina la comunicación I2C
      dato=Serial.read();
     break;
     case '3':
      Wire.beginTransmission(6);                                               //Empieza la comunicación I2C
      Wire.write(dato);                                                        //Envió dato
      Wire.endTransmission();                                                  //Termina la comunicación I2C
      dato=Serial.read();
     break;
     default:
     Serial.println(" ");
     Serial.println("Caracter ingresado no valido");
     Serial.println("Ingrese nuevamente");
     Serial.println(" ");
     break;

   }
            
 } 

}
