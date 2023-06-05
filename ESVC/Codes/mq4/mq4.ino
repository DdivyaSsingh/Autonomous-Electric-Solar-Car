void setup() {
  Serial.begin(9600);
 
}

void loop() {
  int sensorValueMQ4 = analogRead(A1);
  Serial.println(sensorValue);
  delay(100);

  int sensorValueMQ7 = analogRead(A2);
  Serial.println(sensorValue);
  delay(100);
  
}
