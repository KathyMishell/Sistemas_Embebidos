/*
 * CAPITULO V: PERIFERICOS ESPECIALES
 * CODE 17: USO DE TIMER 2
 * OBJETIVO: Reloj con Timer 2
 * NOMBRE: Katherine Guatemal
 *
 * FUNCIONES:  MsTimer2::set(1000,flash);//1s periodo
 *             MsTimer2::start();
 *             MsTimer2::stop();
 *
*/

#include <MsTimer2.h>                //libreria Timer 2
#include <LiquidCrystal.h>            //libreria lcd

LiquidCrystal lcd(13,12,11,10,9,8);  //objeto libreria lcd
int segundos=0;                      //variable de segundos
int minutos=0;                       //variable de minutos
int horas=0;                         //variable de horas
int u=0;

void setup() {
  lcd.begin(20,4);
  MsTimer2::set(1000,reloj);
  MsTimer2::start();
}

void loop() {
 Serial.println("PROGRAMA PRINCIPAL");//Simulacion del programa principal
 delay(300);
}
void reloj(){
  if(segundos<60){                    //Condición de segundos
    segundos++;                       //incrementar variable
  }else{
   segundos=0;
   if(minutos<60){                    //Condición de minutos
     minutos++;                       //incrementar variable
   }else{
     minutos=0;
      if(horas<24){                   //Condición de Horas
        horas++;                      //incrementar variable
      }else{
        horas=0;
      }     
   }
  }
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.println("Bienvenido");
  lcd.setCursor(0,1);
  lcd.println("Katherine Guatemal");
  lcd.setCursor(1,2); 
  lcd.print("Horas:Minutos: Seg");  
  lcd.setCursor(6,3);
  lcd.print(String(horas)+String(":")+String(minutos)+String(":")+String(segundos));
}
