/*
 * DEBER 5.2
 * UNIDAD V :FUNCIONES ESPECIFICAS 
 * CODIGO 23:MANEJO DE MODOS SLEEP (MODIFICADO)
 * OBJETIVO:REALIZAR UN CONTROL DE MODOS SLEEP POR MEDIO DE INTERRUPCIONES
 * MODO SLEEP Y DE AHORRO DE BATERIA
 *   Consumo es de 100-500mA
 *   Ahorro de bateria es hasta 10mA
 *   Librerias: avr/slepp.h
 *              avr/power.h
 *Nombre: Guatemal Katherine
 */

#include<avr/power.h>
#include <avr/interrupt.h>
#include<avr/sleep.h>
#include<avr/wdt.h>
#include<MsTimer2.h>
#include<EEPROM.h>
int dato;
int on=0;

void(*resetFunc) (void) = 0;                                        //Función de Reseteo //void on(void)
void setup() {                                                 
   dato=EEPROM.read(0);                                             //Lectura de la EEPROM en 0
   Serial.begin(9600);                                              //Inicializar la comunicación serial
   Serial.println("SETUP");                                         //Envió de mensaje "SETUP"
   if(dato==0){                                                     //Condición si el dato es 0
    set_sleep_mode(SLEEP_MODE_STANDBY);                             //Indica el Modo Sleep
    sleep_enable();                                                 //Habilita el Sleep
    EEPROM.write(0,1);                                              //Escritura de la EEPROM
    wdt_enable(WDTO_8S);                                            //Ciclo wdt_enable de 8s
    }
    else{                                                           //Condición contraria
    sleep_disable();                                                //Desabilitar el modo sleep
     EEPROM.write(0,0);                                             //Escritura de la EEPROM
      MsTimer2::set(10000,tiempo);                                  //Configuración timer 2 a un segundo
      MsTimer2::start();                                            //Inicio del timer 2
    }
   attachInterrupt(0,encender,LOW);                                 //Configuración de entrada del switch
}
void loop() {                                                       
if(dato==0){                                                        //Condición si dato es igual 0 
  Serial.println("DORMIDO");                                        //Impresión de Dormido
  delay(2000);                                                      //Delay de espera
  sleep_mode();                                                     //Modo sleep
}
 else{                                                              //Condición de caso contrario
  Serial.println("DESPIERTO");                                      //Mensaje de estado
  delay(1000);                                                      //Delay
  }
}
void tiempo(){                                                      //void de tiempo
  Serial.println("DORMIDO");                                        //Impresión de Dormido
  delay(2000);                                                      //Delay de espera
  sleep_mode();                                                     //Modo sleep
 }
 
 void encender (){                                                  //Función de encender
    resetFunc();                                                    //Llamo al método
 }
