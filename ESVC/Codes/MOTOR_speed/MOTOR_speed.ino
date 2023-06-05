int pin = A0;

void setup() {
  Serial.begin(9600);
  

}

void loop() {
  // put your main code here, to run repeatedly:
  float val= analogRead(pin)*(5000/1024);
  Serial.println(val);

}
