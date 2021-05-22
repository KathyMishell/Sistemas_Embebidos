/*
 * NOMBRE: Katherine Guatemal
 *
 * FUNCIONES: interrupt 0: Inicio del sistema e ingreso de veces de juego
 *                        Inicio del juego
 *                        Fin de Juego
 *                      interrupt 1:Contador
 *                      attachInterrupt(interrupt,rutina,modo)
 *
*/

const int leds [6]={8,9,10,11,12,13};
int on = 0;                           //int0
int cont;                           //int1
int i;                              //variable de conteo
int j=0;                            //variable de conteo


void setup() {
  for(i=0;i<6;i++){                 //configuración de leds            
    pinMode(leds[i],OUTPUT);

  }
i=0;                              
Serial.begin(9600);                 //activición de la comunicacion serial
attachInterrupt(0,activation,LOW);  //Interrupción 0 se habilita
attachInterrupt(1,contador,LOW);     //Interupción 1 habilitada

}

void loop() {
if(on==3){
 for(;i<cont;i++){
    for(j=0;j<6;j++){
      digitalWrite(leds[j],HIGH);
      delay(200);
      digitalWrite(leds[j],LOW);
      delay(200);           
    }
 }    
}  
 
}
void activation(){
  switch(on){                     //opciones de botones a definir
    case 0:
    Serial.println("Inicio del Sistema");    
    Serial.println(" Formato:");
    Serial.println("1.Ingrese el numero de veces que desee jugar");
    Serial.println("2.Inicio de Juego");
    on++;
    break; 
    case 1:
    Serial.println("Ingrese el numero de veces que desee jugar");
    on++;
    break;           
    case 2:
    Serial.println("Inicio de Juego");
    on++;
    break;
    case 3:
    Serial.println("Fin de juego");
    cont=0;
    on=0;
    i=0;      
    break;  
    }  
}
void contador(){
if(on==2){  
  cont++;
  Serial.println(String("Juega ")+String(cont)+String(" veces"));  
  }  
}