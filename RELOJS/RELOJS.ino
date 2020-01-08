#include <Wire.h>
#include <RTClib.h>

RTC_DS3231 rtc;

int led[] = {2, 3, 4, 5, 6, 7,8,9,10,11,12,13};//LED GENERALES
int ledM[] = {1, A0, A1, A2, A3};//LED PARA INDICADOR DE MINUTOS
int hor = 0, mit = 0, seg = 0;//DEFINE LOS CONTADORES DE HORA, MINUTOS Y SEGUNDOS

void setup() {
  Serial.begin(9600);
  
  if(!rtc.begin()){//SI EL MODULO RTC ESTA EN EL HW
    Serial.print("MODULO RTC NO ENCONRADO :-(");
    hor = 1;
    mit = 1;
    seg = 1;
    }else{
      
    //rtc.adjust(DateTime(__DATE__,__TIME__));//ESTABLECE LA HORA DEL RTC, SOLO CARGARLO UNA VEZ
    
    hor = (rtc.now().hour()%12);
    mit = (rtc.now().minute());
    seg = (rtc.now().second());
    }

    for(int i=0;i<12;i++){
      pinMode(led[i], OUTPUT);   // ESTABLECER PIN DE SALIDA PRINCIPAL
      if(i<5){
        pinMode(ledM[i], OUTPUT);   // ESTABLECER PIN DE SALIDA MINUTOS
      }
    }
}

void loop() {

    Serial.print(hor,DEC); // A§o
    Serial.print(':');
    Serial.print(mit,DEC); // Mes
    Serial.print(':');
    Serial.print(seg,DEC); // Dia
    Serial.println(' ');
    
    digitalWrite(led[hor],HIGH);
    digitalWrite(led[mit/5],HIGH);

    delay(500);
    digitalWrite(led[mit/5],LOW);
    delay(500);
    if(mit%5 !=0 || mit == 0){//PARA ENCENDER LOS LED DE MINUTOS
      analogWrite(ledM[mit%5],250);
      if(mit>0){
        for(int i = 0;i<mit%5;i++){
        analogWrite(ledM[i],250);
      }
      }
    }else{
      for(int i = 1;i<5;i++){
       analogWrite(ledM[i],0);
      }
    }
    
    if(mit==60){
      digitalWrite(led[hor],LOW);
      hor++;
      mit=0;
    }
    if(seg==60){
      digitalWrite(led[mit/5],LOW);
      mit++;
      seg=0;
    }
    
    seg++;
}
