int ledPins[] = {2, 3, 4, 5, 6, 7, 8, 9, 10, 11};

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
  for (int i = 0; i < 9; i++) {
    pinMode(ledPins[i], OUTPUT);   // sets ledPins as output
  }
}

void loop() {
  secuencial();
  escalera(2, 2, random(100, 300));
  aleatorio_gradual(4, random(1, 4));
  gradual_descendente(2, random(1, 5));
  gradual(2, random(1, 4));
  rafagas(2, 3, random(100, 300), random(400, 600));
  varios_gradual(2, 2, random(1, 5));
  varios_rafagas(2, 2, random(100, 300));
  todo(2, 1);
}

void secuencial() {
  int j = 100;
  for (int i = 0; i < 9; i++) {
    analogWrite(ledPins[i], 100);
    j = j + (i * 16);
    delay(200);
  }
  for (int i = 0; i < 9; i++) {
    analogWrite(ledPins[i], 10);
  }
  delay(300);
}

void gradual(int repeticiones, int velocidad) {
  int j = 0;
  for (int m = 1; m <= repeticiones; m++) {
    analogWrite(ledPins[j], 255);
    j = j + 1;
    for (j; j < 9; j++) {
      for (int i = 0; i <= 255; i++) {
        analogWrite(ledPins[j], i);
        analogWrite(ledPins[j - 1], 255 - i);
        delay(velocidad);
      }
    }
  }
}

void gradual_descendente(int repeticiones, int velocidad) {
  for (int i = 0; i < 9; i++) {
    analogWrite(ledPins[i], 0);
  }
  int count = 0;
  for (int m = 1; m <= repeticiones; m++) {
    for (int n = 0; n <= 9; n++) {
      for (int i = 0; i <= 255; i++) {
        analogWrite(ledPins[n], i);
        if (n == 0 && count > 0) {
          analogWrite(ledPins[3], 255 - i);
        }
        else {
          analogWrite(ledPins[n - 1], 255 - i);
        }
        delay(velocidad);
      }
      count++;
    }
  }
  for (int i = 255; i >= 0; i--) {
    analogWrite(ledPins[3], i);
    delay(velocidad);
  }
}

void aleatorio_gradual(int repeticiones, int velocidad) {
  int vector[9];

  for (int n = 1; n <= repeticiones; n++) {
    for (int i = 0; i < 9; i++) {
      vector[i] = random(2);
    }

    Serial.print(vector[0]);
    Serial.print(vector[1]);
    Serial.print(vector[2]);
    Serial.println(vector[3]);

    for (int i = 0; i <= 255; i++) {
      int j = 0;
      analogWrite(ledPins[j], vector[j]*i);
      j++;
      analogWrite(ledPins[j], vector[j]*i);
      j++;
      analogWrite(ledPins[j], vector[j]*i);
      j++;
      analogWrite(ledPins[j], vector[j]*i);
      j++;
      analogWrite(ledPins[j], vector[j]*i);
      j++;
      analogWrite(ledPins[j], vector[j]*i);
      j++;
      analogWrite(ledPins[j], vector[j]*i);
      j++;
      analogWrite(ledPins[j], vector[j]*i);
      j++;
      analogWrite(ledPins[j], vector[j]*i);
      j++;
      delay(velocidad);
    }
    for (int i = 255; i >= 0; i--) {
      int j = 0;
      analogWrite(ledPins[j], vector[j]*i);
      j++;
      analogWrite(ledPins[j], vector[j]*i);
      j++;
      analogWrite(ledPins[j], vector[j]*i);
      j++;
      analogWrite(ledPins[j], vector[j]*i);
      j++;
      analogWrite(ledPins[j], vector[j]*i);
      j++;
      analogWrite(ledPins[j], vector[j]*i);
      j++;
      analogWrite(ledPins[j], vector[j]*i);
      j++;
      analogWrite(ledPins[j], vector[j]*i);
      j++;
      analogWrite(ledPins[j], vector[j]*i);
      j++;
      delay(velocidad);
    }
  }
}

void escalera(int repeticiontotal, int repeticiones, int velocidad1) {
  for (int m = 1; m <= repeticiontotal; m++) {
    for (int i = 1; i <= repeticiones; i++) {
      for (int n = 0; n <= 8; n++) {
        analogWrite(ledPins[n], 255);
        delay(velocidad1);
      }
      for (int n = 0; n <= 8; n++) {
        analogWrite(ledPins[n], 0);
        delay(velocidad1);
      }
    }
    for (int i = 1; i <= repeticiones; i++) {
      for (int n = 8; n >= 0; n--) {
        analogWrite(ledPins[n], 255);
        delay(velocidad1);
      }
      for (int n = 8; n >= 0; n--) {
        analogWrite(ledPins[n], 0);
        delay(velocidad1);
      }
    }
  }
}

void rafagas(int repeticiones, int rafagas, int velocidad1, int velocidad2) {
  for (int m = 1; m <= repeticiones; m++) {
    for (int n = 1; n <= rafagas; n++) {
      for (int j = 0; j < 9; j++) {
        analogWrite(ledPins[j], 255);
      }
      delay(velocidad1);
      for (int j = 0; j < 9; j++) {
        analogWrite(ledPins[j], 0);
      }
      delay(velocidad1);
    }
    delay(velocidad2);
  }
}

void varios_gradual(int repeticiontotal, int repeticiones, int velocidad) {
  for (int m = 1; m <= repeticiontotal; m++) {
    for (int l = 1; l <= repeticiones; l++) {
      for (int j = 0; j < 9; j++) {
        for (int i = 0; i <= 255; i++) {
          analogWrite(ledPins[j], i);
          delay(velocidad);
          analogWrite(ledPins[j], 0);
        }
      }
    }
  }
}

void varios_rafagas(int repeticiones, int rafagas, int velocidad1) {
  for (int m = 1; m <= repeticiones; m++) {
    for (int n = 1; n <= rafagas; n++) {
      for (int j = 0; j < 9; j += 2) {
        for (int i = 0; i <= 255; i++) {
          analogWrite(ledPins[j], 255);
          analogWrite(ledPins[j + 1], 255);
          delay(velocidad1);
          analogWrite(ledPins[j], 0);
          analogWrite(ledPins[j + 1], 0);
          delay(velocidad1);
        }
      }
      for (int n = 1; n <= rafagas; n++) {
        for (int j = 0; j < 9; j += 2) {
          for (int i = 0; i <= 255; i++) {
            analogWrite(ledPins[j], 255);
            analogWrite(ledPins[j + 1], 255);
            delay(velocidad1);
            analogWrite(ledPins[j], 0);
            analogWrite(ledPins[j + 1], 0);
            delay(velocidad1);
          }
        }
      }
    }
  }
}

  void todo(int repeticiones, int velocidad) {
    for (int m = 1; m <= repeticiones; m++) {
      for (int i = 0; i <= 255; i++) {
        for (int n = 0; n <= 8; n++) {
          analogWrite(ledPins[n], i);
          delay(velocidad);
        }
      }
      for (int i = 255; i >= 0; i--) {
        for (int n = 0; n <= 8; n++) {
          analogWrite(ledPins[n], i);
          delay(velocidad);
        }
      }
    }
  }
