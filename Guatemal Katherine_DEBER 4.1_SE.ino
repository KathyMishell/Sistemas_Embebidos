/* 
 *  
 * DEBER: 4.1 
 * TEMA: CAD Y PWM
 * NOMBRE: Katherine Guatemal
 */

#include <LiquidCrystal.h>
LiquidCrystal lcd(13,12,11,10,9,8);       //seleccion de pines para la LCD
LiquidCrystal lcd1(7,6,5,4,3,2);       //seleccion de pines para la LCD
int conversor;                          //Variables para adquirir datos del conversor a voltaje
float voltaje;                          //variable de conversion de conversor a voltaje
int dutty;                              //variable para el uso de pwm
const int btn =A5;
const int sw =A4;

void setup(){
  lcd.begin(16,2);                      //inicializa la LCD
  lcd1.begin(16,2);                      //inicializa la LCD
  pinMode(btn,INPUT);                  //Entrada digital pin A5
  pinMode(sw,INPUT);                     //Entrada digital pin A4
} 

void loop(){
 while(digitalRead(sw)==HIGH){  
 conversor=analogRead(A0);              //lectura del canal A0-0-14
 voltaje=(conversor*5.0)/1023.0;        //converson de voltaje
 dutty=conversor/4;                     //cambio la escala para el dutty cicle
 analogWrite(2,dutty);                 //envio del valor al pin 11
 lcd.setCursor(0,0);
 lcd.print("CAD:");
 lcd.setCursor(5,0);
 lcd.print(conversor);
 lcd.setCursor(0,1);
 lcd.print("V:");
 lcd.setCursor(3,1);
 lcd.print(voltaje);
 lcd.setCursor(9,1);
 lcd.print("PWM:"); 
 lcd.setCursor(13,1);
 lcd.print((dutty*100)/255);
 delay(300);  
 lcd.clear(); 
} 
if (digitalRead(btn)==LOW){  
  lcd1.clear(); 
 while (digitalRead(btn)==HIGH){  
 conversor=analogRead(A1);              //lectura del canal A1-0-14
 voltaje=(conversor*5.0)/1023.0;        //converson de voltaje
 dutty=conversor/4;                     //cambio la escala para el dutty cicle
 analogWrite(2,dutty);                 //envio del valor al pin 11
 lcd1.setCursor(0,0);
 lcd1.print("CAD:");
 lcd1.setCursor(5,0);
 lcd1.print(conversor);
 lcd1.setCursor(0,1);
 lcd1.print("V:");
 lcd1.setCursor(3,1);
 lcd1.print(voltaje);
 lcd1.setCursor(9,1);
 lcd1.print("PWM:"); 
 lcd1.setCursor(13,1);
 lcd1.print((dutty*100)/255);
 delay(300);  
 lcd1.clear(); 
 }

} 
  }