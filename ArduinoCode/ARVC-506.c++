#define TRIGGER_PIN    12      // Pino de trigger do sensor ultrassônico
#define ECHO_PIN       11      // Pino de echo do sensor ultrassônico
#define MAX_DISTANCE   200     // Distância máxima em cm (limite do sensor)
#define PIN_LED        9       // Pino do LED
#define BUZZER_PIN     8       // Pino do Buzzer ou Speaker
#define DIST_THRESHOLD 60      // Distância em cm para acionar o som
#define SENSOR         7       // Define o pino do sensor de inclinação

int sensor;

void setup() {
  Serial.begin(9600);
  pinMode(TRIGGER_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
  pinMode(BUZZER_PIN, OUTPUT);
  pinMode(PIN_LED, OUTPUT);
  pinMode(SENSOR, INPUT); 
}

void loop() {
  long duration, distance;
  
  // Medição da distância com o sensor ultrassônico
  digitalWrite(TRIGGER_PIN, LOW); 
  delayMicroseconds(2); 
  digitalWrite(TRIGGER_PIN, HIGH);
  delayMicroseconds(10); 
  digitalWrite(TRIGGER_PIN, LOW);
  
  duration = pulseIn(ECHO_PIN, HIGH);
  distance = (duration / 2) / 29.1; // Corrigido o cálculo da distância em cm
  
  // Verificação da distância para acionar o som e o LED
  if (distance <= DIST_THRESHOLD) {
    tone(BUZZER_PIN, 1000); // Emite um som de 1kHz no Buzzer ou Speaker
    digitalWrite(PIN_LED, HIGH); // Liga o LED
    delay(100); // Tempo que o som vai durar em milissegundos
  } else {
    noTone(BUZZER_PIN); // Para de emitir som
    digitalWrite(PIN_LED, LOW); // Desliga o LED
  }
  
  // Leitura do sensor de inclinação
  sensor = digitalRead(SENSOR);
  if (sensor == HIGH) {
    Serial.println("Inclinacao detectada!"); 
    digitalWrite(PIN_LED, HIGH);
  }
  
  // Saída da distância medida via serial
  Serial.print("Distancia: ");
  Serial.print(distance);
  Serial.println(" cm");
  
  delay(500); // Delay entre as medições
}
