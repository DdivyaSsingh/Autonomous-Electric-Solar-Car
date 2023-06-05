int enA = 2;
int in1 = 1; 
int in2 = 3; 

int enB = 6;
int in3 = 5;
int in4 = 7;

void clockRotate(){
   
    int starttime = millis();
    int endtime = starttime;
    while ((endtime - starttime) <= 4313) // do this loop for up to 5000mS
    {
      // code here
      digitalWrite(in1,LOW); 
      digitalWrite(in2,LOW);
      digitalWrite(in3,LOW);
      digitalWrite(in4,HIGH);
      analogWrite(enA,250);
      analogWrite(enB,250);

      endtime = millis();
    }
      analogWrite(enA,0);
      analogWrite(enB,0);
     
}

void anticlockRotate(){

      
    int starttime = millis();
    int endtime = starttime;
    while ((endtime - starttime) <= 3613) // do this loop for up to 5000mS
    {
      // code here
      digitalWrite(in1,HIGH); 
      digitalWrite(in2,LOW);
      digitalWrite(in3,LOW);
      digitalWrite(in4,LOW);
      analogWrite(enA,250);
      analogWrite(enB,250);

      endtime = millis();
    }
      analogWrite(enA,0);
      analogWrite(enB,0);
     
}

void mover(){
    int starttime = millis();
    int endtime = starttime;
    int loopcount = 0;
    while ((endtime - starttime) <= 5000) // do this loop for up to 5000mS
    {
      // code here
      digitalWrite(in1,HIGH);
      digitalWrite(in2,LOW);
      digitalWrite(in3,LOW);
      digitalWrite(in4,HIGH);
      analogWrite(enA,250);
      analogWrite(enB,250);

      loopcount = loopcount+1;
      endtime = millis();
    }
      analogWrite(enA,0);
      analogWrite(enB,0);  
}

void setup() {
  // put your setup code here, to run once:

    pinMode(enA,OUTPUT);
    pinMode(in1,OUTPUT);
    pinMode(in2,OUTPUT);
    pinMode(enB,OUTPUT);
    pinMode(in3,OUTPUT);
    pinMode(in4,OUTPUT);


    mover();
    clockRotate();
    anticlockRotate();
}

void loop() {
  // put your main code here, to run repeatedly:

}
