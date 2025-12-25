int waterSensorPin = A0;
int low_led = 10;
int med_led = 11;
int high_led = 12;
int buzzer = 13;

void setup() {
  Serial.begin(9600);
  pinMode(low_led, OUTPUT);
  pinMode(med_led, OUTPUT);
  pinMode(high_led, OUTPUT);
  pinMode(buzzer, OUTPUT);
}

int getAverageSensorValue() {
  long sum = 0;
  for (int i = 0; i < 10; i++) {
    sum += analogRead(waterSensorPin);
    delay(5);
  }
  return sum / 10;
}

void loop() {
  int sensorValue = getAverageSensorValue();

  Serial.print("Water Level: ");
  Serial.println(sensorValue);

  digitalWrite(low_led, LOW);
  digitalWrite(med_led, LOW);
  digitalWrite(high_led, LOW);
  digitalWrite(buzzer, LOW);

  if (sensorValue >= 360) {
    digitalWrite(high_led, HIGH);
    digitalWrite(buzzer, HIGH);
    delay(200);
    digitalWrite(buzzer, LOW);
    delay(200);
    digitalWrite(buzzer, HIGH);
    delay(200);
    digitalWrite(buzzer, LOW);
    delay(400);
  } else if (sensorValue >= 270) {
    digitalWrite(med_led, HIGH);
    delay(1000);
  } else if (sensorValue >= 170) {
    digitalWrite(low_led, HIGH);
    delay(1000);
  } else {
    digitalWrite(buzzer, HIGH);
    delay(1000);
    digitalWrite(buzzer, LOW);
    delay(500);
  }

  delay(200);
}
