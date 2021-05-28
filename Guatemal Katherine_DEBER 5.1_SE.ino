/*
 * CAPITULO V: FUNCIONES ESPECIALES
 * Deber 5.1
 * OBJETIVO: Ingresar por tecaldo matricial 15 datos para guardar en la EEPROM y posteriormente Mostrar en la lcd
 * NOMBRE: Katherine Guatemal           
 * 
 */
#include<LiquidCrystal.h>         // Incluimos la libreria LiquidCrystal
#include <Keypad.h>               //Incluimos la libreria keypad
#include <EEPROM.h>               //Incluimos la libreria de EEPROM       

const int led1=5;
const byte Fila = 4;              //variable para las filas del teclado
const byte Col = 4;                //variable para las columnas del teclado
const byte filaPins[Fila] = { 13, 12, 11, 10 };    //vector para las filas del teclado
const byte columnaPins[Col] = { 9, 8, 7, 6 };      //vector para las columnas del teclado
int k=19;
char TECLA;   

                                
char keys[Fila][Col] = {
  {'7','8','9','A'},
  {'4','5','6','B'},
  {'1','2','3','C'},
  {'N','0','OK','D'}
};

Keypad teclado= Keypad(makeKeymap(keys),filaPins,columnaPins,Fila,Col);

LiquidCrystal lcd(A0,A1,A2,A3,A4,A5);

void setup() {
   Serial.begin(9600);
   lcd.begin(20,4);
   pinMode(led1,OUTPUT);
  Serial.println("Presine culaquier tecla para iniciar "); 
  delay(500); 

}

void loop() {   
   TECLA = teclado.getKey();
   if(TECLA){
   Serial.println(TECLA);      
    if(TECLA=='OK'){
      lcd.setCursor(1,0);     
      lcd.print("Lectura de Memoria");
      for(int i=0;i<=14;i++){
      lcd.setCursor(k,1);
      k--;
      lcd.print(EEPROM.read(0));
      delay(150);
    }
  }
  else{
    Serial.println("Almacenamiento 15 datos:");     
    for(int i=0;i<=14;i++){

        digitalWrite(led1,HIGH);
        delay(900);
      char TECLA1 = teclado.getKey();
        int dato=int(TECLA1);
        delay(900);
        dato=map(dato,0,1023,0,255);        
        EEPROM.write(i,dato);
        Serial.println(dato);
        digitalWrite(led1,LOW);
        delay(500);           
        lcd.clear();
        k=19;            
    }
  }
 }

}
