/*
 * CAPÍTULO II: PUERTOS DIGITALES
 * CÓDIGO 2: Manejo de ciclos de progamación con puertos de entrada-salida.
 * OBJETIVO: encender y apagar leds en dependencia de botones y switches
 * NOMBRE:Katherine Guatemal 
 *  No necesitan librerías
 * Funciones de programación:
 *           pinMode(pin,MODO)
 *           pinRead(pin)
 *           delay(ms)
 */
 //variables: númericas enteras (int), decimales (float), caracteres (chart)

const int led1 = 8;
const int led2 = 9;
const int led3 = 10;
const int btn1 = 7;
const int btn2 = 6;
const int sw1 = 5;
int i=0;


void setup() {
  pinMode(led1,OUTPUT); //declaro el pin 8 como salida
  pinMode(led2,OUTPUT); //declaro el pin 9 como salida
  pinMode(led3,OUTPUT); //declaro el pin 10 como salida
  pinMode(btn1,INPUT);  //declaro el pin 7 como entrada
  pinMode(btn2,INPUT);  //declaro el pin 6 como entrada
  pinMode(sw1,INPUT);   //declaro el pin 5 como entrada
  
  }

void loop() {
 // Ciclo if, el led1 se prende 9 veces  
 if(digitalRead(sw1)==LOW){   //condición del ciclo if                 
    digitalWrite(led1,HIGH);  //Envia 5V al pin8
    }   

    else{
      digitalWrite(led1,LOW);    //Envio 0V al pin8
    } 
/*
 if(digitalRead(btn2)==HIGH){   //condición que active el btn1 en alto           
    digitalWrite(led2,HIGH);     //Envia 5V al pin9
    }   
    else{
      digitalWrite(led2,LOW);   //Envio 0V al pin9
    } 
*/
 if(digitalRead(btn2)==HIGH){           
     delay(300);               //delay anti-rebotes
     i=1-i;                    //Condición booleana
     if(i==0){
      digitalWrite(led2,HIGH);  //Envia 5V al pin9
      }
     else{
      digitalWrite(led2,LOW);
      }
    }
 if(digitalRead(btn1)==LOW){           
      delay(300);                             //delay anti-rebotes
      digitalWrite(led3,!digitalRead(led3));  //Función Toggle
      }
}
