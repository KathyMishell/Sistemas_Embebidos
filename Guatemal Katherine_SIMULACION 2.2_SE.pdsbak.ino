/*
 * CAPÍTULO II: PUERTOS DIGITALES
 * CÓDIGO 2: Manejo de ciclos de progamación con puertos de salida.
 * OBJETIVO: Uso de ciclos: while, if y for.
 *           No se necesita librerías
 * NOMBRE:Katherine Guatemal 
 * Funciones de programación:
 *           if(condición)  
 *           {
 *           instrucciones 
 *           }  
 *           else
*           {
 *           instrucciones 
 *           }    
 *          while (Condición)
 *           {
 *           instrucciones 
 *           }       
 *           for(inicio de la variable. condición, tipo de aumento)  
 *           {
 *           instrucciones 
 *           }                    
 */
 //variables: númericas enteras (int), decimales (float), caracteres (chart)

#define led1 8          //uso de #define, es una variable que no se puede alterar su valor, no existe depuraciones
int led2 = 9   ;        // se puede considerar como una veriable normal, no es muy recomendable
const int led3 = 10 ;  // variable constante, es la recomendable
int i=0;
int j=0;
int k; 

void setup() {
  pinMode(led1,OUTPUT); //declaro el pin 8 como salida
  pinMode(led2,OUTPUT); // declaro el pin 9 como salida
  pinMode(led3,OUTPUT); //declaro el pin 10 como salida
}

void loop() {
 // Ciclo if, el led1 se prende 9 veces  
 if(i<10){                     //condición del ciclo if                 
    digitalWrite(led1,HIGH);  //Envia 5V al pin8
    delay(500);               //Se tiene el microcontrolador por medio segundo
    digitalWrite(led1,LOW);   //Envia 0v al pin8  
    delay(500);               //Se tiene el microcontrolador por medio segundo
    i++;                      //aumento de variable uno en uno
    }    
 // Ciclo while, el led2 se enciende y apaga 11
 while (j<=10){
    j++;
    digitalWrite(led2,HIGH);
    delay(500);
    digitalWrite(led2,LOW);
    delay(500);
    }
// Ciclo for, el led3 se enciende y apaga 11 veces cada 500ms
 for(k=0,k<=10;k++){
    digitalWrite(led3,HIGH);
    delay(500);
    digitalWrite(led3,LOW);
    delay(500);
    }    
}
