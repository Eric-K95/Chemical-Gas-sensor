//Exercise: MQ7 sensor (Chemical&Gas detection sensor)
//designed by JIN-WOO KIM

int LED1 = 13; //Red LED
int LED2 = 12; //Yellow LED
int LED3 = 11; //Green LED
int LED4 = 10; //Blue LED
int buzzer = 8;
int mq7Pin = A0;
int sensorThreshold = 500;

void setup() {
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(LED3, OUTPUT);
  pinMode(LED4, OUTPUT);
  pinMode(buzzer, OUTPUT);
  pinMode(mq7Pin, INPUT);
  Serial.begin(9600);
}

void loop() {
  int Alcohol_LV = analogRead(mq7Pin);
  Serial.print("Alcohol_LV: ");
  Serial.println(Alcohol_LV);
  // Checks if it has reached the threshold value
  if ((Alcohol_LV > 400) && (Alcohol_LV <= 600))   {
    digitalWrite(LED4, HIGH);
    delay(1000);
    digitalWrite (LED3, LOW);
    digitalWrite (LED2, LOW);
    digitalWrite (LED1, LOW);
    tone(buzzer, 300, 100);
  }
  if ((Alcohol_LV > 600) && (Alcohol_LV <= 700))  {
    digitalWrite(LED4, HIGH);
    digitalWrite (LED3, HIGH);
    delay(500);
    digitalWrite (LED2, LOW);
    digitalWrite (LED1, LOW);
    tone(buzzer, 500, 100);
  }
  if ((Alcohol_LV > 700) && (Alcohol_LV <= 800))  {
    digitalWrite(LED4, HIGH);
    digitalWrite (LED3, HIGH);
    digitalWrite (LED2, HIGH);
    delay(300);
    digitalWrite (LED1, LOW);
    tone(buzzer, 1000, 100);
  }
  if (Alcohole_LV > 800) {
    digitalWrite(LED4, HIGH);
    digitalWrite (LED3, HIGH);
    digitalWrite (LED2, HIGH);
    digitalWrite (LED1, HIGH);
    delay(100);
    tone(buzzer, 2000, 100);
  }
  if (Alcohol_LV <= 400) {
    digitalWrite(LED4, LOW);
    digitalWrite (LED3, LOW);
    digitalWrite (LED2, LOW);
    digitalWrite (LED1, LOW);
    noTone(buzzer);
  }
}
