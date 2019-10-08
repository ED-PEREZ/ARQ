int ledPins[] = {6,9,10,11};

void secuencial();
void gradual_descendente(int repeticiones, int velocidad);
void aleatorio_gradual(int repeticiones, int velocidad);
void escalera(int repeticiontotal, int repeticiones, int velocidad);
void gradual(int repeticiones, int velocidad);
void rafagas(int repeticiones, int rafagas, int velocidad1, int velocidad2);
void varios_gradual(int repeticiontotal, int repeticiones, int velocidad);
void varios_rafagas(int repeticiones, int rafagas, int velocidad1);
void todo(int repeticiones, int velocidad);

void setup() {
  Serial.begin(9600); 
  randomSeed(analogRead(0));
  pinMode(ledPins[0], OUTPUT);   // sets ledPins as output
  pinMode(ledPins[1], OUTPUT);
  pinMode(ledPins[2], OUTPUT);
  pinMode(ledPins[3], OUTPUT);
}

void loop() {
  secuencial();
  escalera(2,2,random(100,300));
  aleatorio_gradual(4,random(1,4));
  gradual_descendente(2, random(1,5));
  gradual(2,random(1,4));
  rafagas(2,3,random(100,300),random(400,600));
  varios_gradual(2,2,random(1,5));
  varios_rafagas(2,2,random(100,300));
  todo(2, 1);
}

void secuencial(){
  analogWrite(ledPins[0],100);
  delay(200);
  analogWrite(ledPins[1],150);
  delay(200);
  analogWrite(ledPins[2],200);
  delay(200);
  analogWrite(ledPins[3],250);
  delay(200);
  analogWrite(ledPins[0],10);
  analogWrite(ledPins[1],10);
  analogWrite(ledPins[2],10);
  analogWrite(ledPins[3],10);
  delay(300);
}

void gradual(int repeticiones, int velocidad){
  for(int m=1; m<=repeticiones;m++){
      analogWrite(ledPins[0], 255);
  
    for (int i=0; i<=255; i++){
      analogWrite(ledPins[1], i);
      analogWrite(ledPins[0],255-i);
      delay(velocidad);
    }
    for (int i=0; i<=255; i++){
      analogWrite(ledPins[2], i);
      analogWrite(ledPins[1],255-i);
      delay(velocidad);
    }
    for (int i=0; i<=255; i++){
      analogWrite(ledPins[3], i);
      analogWrite(ledPins[2],255-i);
      delay(velocidad);
    }
    for (int i=0; i<=255; i++){
      analogWrite(ledPins[2], i);
      analogWrite(ledPins[3],255-i);
      delay(velocidad);
    }
    for (int i=0; i<=255; i++){
      analogWrite(ledPins[1], i);
      analogWrite(ledPins[2],255-i);
      delay(velocidad);
    }
    for (int i=0; i<=255; i++){
      analogWrite(ledPins[0], i);
      analogWrite(ledPins[1],255-i);
      delay(velocidad);
    }
  }
}

void gradual_descendente(int repeticiones, int velocidad){
  analogWrite(ledPins[0],0);
  analogWrite(ledPins[1],0);
  analogWrite(ledPins[2],0);
  analogWrite(ledPins[3],0);
  int count = 0;
  for (int m=1; m<=repeticiones; m++){ 
    for (int n=0; n<=3; n++){
      for (int i=0; i<=255; i++){
        analogWrite(ledPins[n], i);
        if (n == 0 && count > 0){
          analogWrite(ledPins[3],255-i);
        }
        else{
          analogWrite(ledPins[n-1],255-i);
        }
        delay(velocidad);
      }
      count++;
    }
  }
  for (int i=255; i>=0; i--){
    analogWrite(ledPins[3],i);
    delay(velocidad);
  }
}

void aleatorio_gradual(int repeticiones, int velocidad){
  int vector[3];
  for(int n=1;n<=repeticiones;n++){
      vector[0]=random(2);
      vector[1]=random(2);
      vector[2]=random(2);
      vector[3]=random(2);

    Serial.print(vector[0]);
    Serial.print(vector[1]);
    Serial.print(vector[2]);
    Serial.println(vector[3]);
   
    for(int i=0;i<=255;i++){
      analogWrite(ledPins[0], vector[0]*i);
      analogWrite(ledPins[1], vector[1]*i);
      analogWrite(ledPins[2], vector[2]*i);
      analogWrite(ledPins[3], vector[3]*i);
      delay(velocidad);
    }
    for(int i=255;i>=0;i--){
      analogWrite(ledPins[0], vector[0]*i);
      analogWrite(ledPins[1], vector[1]*i);
      analogWrite(ledPins[2], vector[2]*i);
      analogWrite(ledPins[3], vector[3]*i);
      delay(velocidad);
    }
  }
}

void escalera(int repeticiontotal, int repeticiones, int velocidad1){
  for (int m=1;m<=repeticiontotal;m++){
    for(int i=1; i<=repeticiones; i++){    
      for (int n=0; n<=3; n++){
        analogWrite(ledPins[n], 255);
        delay(velocidad1);
      }
      for (int n=0; n<=3; n++){
        analogWrite(ledPins[n], 0);
        delay(velocidad1);
      }
    }
    for(int i=1; i<=repeticiones; i++){    
      for (int n=3; n>=0; n--){
        analogWrite(ledPins[n], 255);
        delay(velocidad1);
      }
      for (int n=3; n>=0; n--){
        analogWrite(ledPins[n], 0);
        delay(velocidad1);
      }
    }
  }
}

void rafagas(int repeticiones, int rafagas, int velocidad1, int velocidad2){
  for (int m=1;m<=repeticiones;m++){
    for (int n=1;n<=rafagas;n++){
      analogWrite(ledPins[0], 255);
      analogWrite(ledPins[1], 255);
      analogWrite(ledPins[2], 255);
      analogWrite(ledPins[3], 255);
      delay(velocidad1);
      analogWrite(ledPins[0], 0);
      analogWrite(ledPins[1], 0);
      analogWrite(ledPins[2], 0);
      analogWrite(ledPins[3], 0);
      delay(velocidad1);
    }
  delay(velocidad2);
  }
}

void varios_gradual(int repeticiontotal, int repeticiones, int velocidad){
  for(int m=1; m<=repeticiontotal;m++){
    for (int l=1;l<=repeticiones;l++){
        for (int i=0; i<=255; i++){
          analogWrite(ledPins[0], i);
          delay(velocidad);
          analogWrite(ledPins[0], 0);
        }
        for (int i=0; i<=255; i++){
          analogWrite(ledPins[2], i);
          delay(velocidad);
          analogWrite(ledPins[2], 0);
        }
        for (int i=0; i<=255; i++){
          analogWrite(ledPins[3], i);
          delay(velocidad);
          analogWrite(ledPins[3], 0);
        }
        for (int i=0; i<=255; i++){
          analogWrite(ledPins[1], i);
          delay(velocidad);
          analogWrite(ledPins[1], 0);
        }
    }
  }
}

void varios_rafagas(int repeticiones, int rafagas, int velocidad1){
  for (int m=1;m<=repeticiones;m++){
    for (int n=1;n<=rafagas;n++){
      analogWrite(ledPins[0], 255);
      analogWrite(ledPins[2], 255);
      delay(velocidad1);
      analogWrite(ledPins[0], 0);
      analogWrite(ledPins[2], 0);
      delay(velocidad1);
      analogWrite(ledPins[1], 255);
      analogWrite(ledPins[3], 255);
      delay(velocidad1);
      analogWrite(ledPins[1], 0);
      analogWrite(ledPins[3], 0);
      delay(velocidad1);
    }
      for (int n=1;n<=rafagas;n++){
      analogWrite(ledPins[1], 255);
      analogWrite(ledPins[2], 255);
      delay(velocidad1);
      analogWrite(ledPins[1], 0);
      analogWrite(ledPins[2], 0);
      delay(velocidad1);
      analogWrite(ledPins[0], 255);
      analogWrite(ledPins[3], 255);
      delay(velocidad1);
      analogWrite(ledPins[0], 0);
      analogWrite(ledPins[3], 0);
      delay(velocidad1);
    }
  }
}

void todo(int repeticiones, int velocidad){
  for(int m=1; m<=repeticiones; m++){  
    for (int i=0; i<=255; i++){
      for (int n=0; n<=3; n++){
        analogWrite(ledPins[n], i);
        delay(velocidad);
      }
    }
    for (int i=255; i>=0; i--){
      for (int n=0; n<=3; n++){
        analogWrite(ledPins[n], i);
        delay(velocidad);
      }
    }
  }  
}
