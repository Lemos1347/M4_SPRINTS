int led1 = 13;
int led2 = 12;
int led3 = 14;
int led4 = 27;
int led5 = 21;
int led6 = 23;
int ldr = 4;
int buzzer = 19;
int button1 = 5;
int button2 = 18;
int tamanhoVetorFrequencias = -1;
int vetorFrequencias[100];

void setup() {
  Serial.begin(115200);
  Serial.println("Hello, ESP32!");
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(led4, OUTPUT);
  pinMode(led5, OUTPUT);
  pinMode(led6, OUTPUT);
  pinMode(ldr, INPUT);
  pinMode(buzzer, OUTPUT);
  pinMode(button1, INPUT_PULLUP);
  pinMode(button2, INPUT_PULLUP);
}

void converterBinario (int num, int *vetor) {
  
  int numero = num;

  for(int i = 0; i<4; i++){

    switch(i){

      case 0:
      vetor[0] = numero % 2;
      numero = numero / 2;
      break;

      case 1:
      vetor[1] = numero % 2;
      numero = numero / 2;
      break;

      case 2:
      vetor[2] = numero % 2;
      numero = numero / 2;
      break;

      case 3:
      vetor[3] = numero % 2;
      numero = numero / 2;
      break;
    }
  }
}

void displayBinario (int *vetor) {
  digitalWrite(led1, LOW);
  digitalWrite(led2, LOW);
  digitalWrite(led3, LOW);
  digitalWrite(led4, LOW);

  int leds[4] = {led1, led2, led3, led4};

  for (int i = 0; i < 4 ; i ++) {
    switch(vetor[i]) {
      case 0:
      digitalWrite(leds[i], LOW);
      break;

      case 1:
      digitalWrite(leds[i], HIGH);
      break;
    }
  }
}


int converterValor (int valor) {
  double novoValor = valor - 32;
  double range = 4063 - 32;

  novoValor = novoValor / range;

  int numeroFinal = novoValor * 15;

  return numeroFinal;
}

void tocarMusica(int num) {
  switch(num) {
    case 0:
    tone(buzzer, 264, 500);
    delay(600);
    break;

    case 1:
    tone(buzzer, 279, 500);
    delay(600);
    break;

    case 2:
    tone(buzzer, 296, 500);
    delay(600);
    break;

    case 3:
    tone(buzzer, 313, 500);
    delay(600);
    break;

    case 4:
    tone(buzzer, 332, 500);
    delay(600);
    break;

    case 5:
    tone(buzzer, 352, 500);
    delay(600);
    break;

    case 6:
    tone(buzzer, 373, 500);
    delay(600);
    break;

    case 7:
    tone(buzzer, 395, 500);
    delay(600);
    break;

    case 8:
    tone(buzzer, 419, 500);
    delay(600);
    break;

    case 9:
    tone(buzzer, 444, 500);
    delay(600);
    break;

    case 10:
    tone(buzzer, 470, 500);
    delay(600);
    break;

    case 11:
    tone(buzzer, 498, 500);
    delay(600);
    break;

    case 12:
    tone(buzzer, 528, 500);
    delay(600);
    break;

    case 13:
    tone(buzzer, 888, 500);
    delay(600);
    break;

    case 14:
    tone(buzzer, 940, 500);
    delay(600);
    break;

    case 15:
    tone(buzzer, 1056, 500);
    delay(600);
    break;
  }
}

void adicionarMusica(int *vetorMusicas, int num) {
  switch(num) {
    case 0:
    vetorFrequencias[tamanhoVetorFrequencias + 1] = 0;
    tamanhoVetorFrequencias += 1;
    Serial.println("Gravei");
    break;

    case 1:
    vetorFrequencias[tamanhoVetorFrequencias + 1] = 1;
    tamanhoVetorFrequencias += 1;
    Serial.println("Gravei");
    break;

    case 2:
    vetorFrequencias[tamanhoVetorFrequencias + 1] = 2;
    tamanhoVetorFrequencias += 1;
    Serial.println("Gravei");
    break;

    case 3:
    vetorFrequencias[tamanhoVetorFrequencias + 1] = 3;
    tamanhoVetorFrequencias += 1;
    Serial.println("Gravei");
    break;

    case 4:
    vetorFrequencias[tamanhoVetorFrequencias + 1] = 4;
    tamanhoVetorFrequencias += 1;
    Serial.println("Gravei");
    break;

    case 5:
    vetorFrequencias[tamanhoVetorFrequencias + 1] = 5;
    tamanhoVetorFrequencias += 1;
    Serial.println("Gravei");
    break;

    case 6:
    vetorFrequencias[tamanhoVetorFrequencias + 1] = 6;
    tamanhoVetorFrequencias += 1;
    Serial.println("Gravei");
    break;

    case 7:
    vetorFrequencias[tamanhoVetorFrequencias + 1] = 7;
    tamanhoVetorFrequencias += 1;
    Serial.println("Gravei");
    break;

    case 8:
    vetorFrequencias[tamanhoVetorFrequencias + 1] = 8;
    tamanhoVetorFrequencias += 1;
    Serial.println("Gravei");
    break;

    case 9:
    vetorFrequencias[tamanhoVetorFrequencias + 1] = 9;
    tamanhoVetorFrequencias += 1;
    Serial.println("Gravei");
    break;

    case 10:
    vetorFrequencias[tamanhoVetorFrequencias + 1] = 10;
    tamanhoVetorFrequencias += 1;
    Serial.println("Gravei");
    break;

    case 11:
    vetorFrequencias[tamanhoVetorFrequencias + 1] = 11;
    tamanhoVetorFrequencias += 1;
    Serial.println("Gravei");
    break;

    case 12:
    vetorFrequencias[tamanhoVetorFrequencias + 1] = 12;
    tamanhoVetorFrequencias += 1;
    Serial.println("Gravei");
    break;

    case 13:
    vetorFrequencias[tamanhoVetorFrequencias + 1] = 13;
    tamanhoVetorFrequencias += 1;
    Serial.println("Gravei");
    break;

    case 14:
    vetorFrequencias[tamanhoVetorFrequencias + 1] = 14;
    tamanhoVetorFrequencias += 1;
    Serial.println("Gravei");
    break;

    case 15:
    vetorFrequencias[tamanhoVetorFrequencias + 1] = 15;
    tamanhoVetorFrequencias += 1;
    Serial.println("Gravei");
    break;
  }
}


void loop() {

  digitalWrite(led1, LOW);
  digitalWrite(led2, LOW);
  digitalWrite(led3, LOW);
  digitalWrite(led4, LOW);

  int leitura = analogRead(ldr);
  int numero = converterValor(leitura);
  int vetorDosLeds[4] = {0, 0, 0, 0}; 
  int controleLed = 0;

  for (int i = 0; i <= 20 ; i++) {

    if (digitalRead(button1) == LOW) {
      Serial.println("Precionado");
      digitalWrite(led5, HIGH);
      delay(500);
      controleLed = 1;

      while(controleLed == 1){
        
        digitalWrite(led1, LOW);
        digitalWrite(led2, LOW);
        digitalWrite(led3, LOW);
        digitalWrite(led4, LOW);

        for (int i = 0; i <= 20; i++) {
          delay(40);
          if (digitalRead(button1) == LOW) {
            controleLed = 0;
            digitalWrite(led5, LOW);
            delay(100);
          }
        }

        leitura = analogRead(ldr);
        numero = converterValor(leitura);

        converterBinario(numero, vetorDosLeds);
        displayBinario(vetorDosLeds);
        delay(100);
        adicionarMusica(vetorFrequencias, numero);
        tocarMusica(numero);
      }
    }

    delay(20);

    if (digitalRead(button2) == LOW && tamanhoVetorFrequencias != -1) {
      digitalWrite(led6, HIGH);

      digitalWrite(led1, LOW);
      digitalWrite(led2, LOW);
      digitalWrite(led3, LOW);
      digitalWrite(led4, LOW);
      delay(500);

      tone(buzzer, 78, 700);
      digitalWrite(led1, HIGH);
      delay(100);
      digitalWrite(led1, LOW);
      delay(100);
      digitalWrite(led2, HIGH);
      delay(100);
      digitalWrite(led2, LOW);
      delay(100);
      digitalWrite(led3, HIGH);
      delay(100);
      digitalWrite(led3, LOW);
      delay(100);
      digitalWrite(led4, HIGH);
      delay(100);
      digitalWrite(led4, LOW);


      for (int i = 0; i <= tamanhoVetorFrequencias ; i++) {
        digitalWrite(led1, LOW);
        digitalWrite(led2, LOW);
        digitalWrite(led3, LOW);
        digitalWrite(led4, LOW);
        delay(300);
        converterBinario(vetorFrequencias[i], vetorDosLeds);
        displayBinario(vetorDosLeds);
        Serial.println(vetorFrequencias[i]);
        tocarMusica(vetorFrequencias[i]);
        delay(800);
      }

      tamanhoVetorFrequencias = -1;
      digitalWrite(led1, LOW);
      digitalWrite(led2, LOW);
      digitalWrite(led3, LOW);
      digitalWrite(led4, LOW);
      delay(500);


      tone(buzzer, 78, 700);
      digitalWrite(led1, HIGH);
      delay(100);
      digitalWrite(led1, LOW);
      delay(100);
      digitalWrite(led2, HIGH);
      delay(100);
      digitalWrite(led2, LOW);
      delay(100);
      digitalWrite(led3, HIGH);
      delay(100);
      digitalWrite(led3, LOW);
      delay(100);
      digitalWrite(led4, HIGH);
      delay(100);
      digitalWrite(led4, LOW);
      digitalWrite(led6, LOW);

    }

    delay(20);
  }


  converterBinario(numero, vetorDosLeds);
  displayBinario(vetorDosLeds);
  tocarMusica(numero); 

}
