int bbtemp = A1;//
int mmtemp = A2;
float temp1;
int btemp;
float temp2;
int mtemp;
float value=0;
float rev=0;
float rpm1;
int rpm;
int smoke;
int rpm2;
int speed2;
int speed;
float speed1;
int oldtime=0;
int time;
void isr()                      //interrupt service routine, only in pin number 2 or pin number 3
{
rev++;
}

void setup()
{Serial.begin(9600);                //initialize LCD
attachInterrupt(0,isr,RISING);  //attaching the interrupt
}

void loop()
{
delay(1000);
detachInterrupt(0);         
time=millis()-oldtime;        //finding total time for one rev 
rpm1=(rev/(time))*60000;         //calculating the rpm
oldtime=millis();             
rev=0;
rpm=round(rpm1/4.44); 
speed1=rpm1*.09156;
speed2=round(speed1);
speed1=speed1*2.25;
speed=round(speed1);
rpm2=round(rpm1);
attachInterrupt(0,isr,RISING);
Serial.print("rpm.val=");
 Serial.print(rpm);
 Serial.write(0xff);                       
  Serial.write(0xff);
  Serial.write(0xff);
  delay(0); 
 Serial.print("speed.val=");
 Serial.print(speed);
 Serial.write(0xff);                       
  Serial.write(0xff);
  Serial.write(0xff);
  delay(0);
   Serial.print("speed2.val=");
 Serial.print(speed2);
 Serial.write(0xff);                       
  Serial.write(0xff);
  Serial.write(0xff);
  delay(0);
   Serial.print("rpm2.val=");
 Serial.print(rpm2);
 Serial.write(0xff);                       
  Serial.write(0xff);
  Serial.write(0xff);
  delay(0); 
  temp1=analogRead(bbtemp);
temp1=temp1*.48848125;
btemp=round(temp1);
Serial.print("temp.val=");
 Serial.print(btemp);
 Serial.write(0xff);                       
  Serial.write(0xff);
  Serial.write(0xff);
  Serial.write("\n");
  delay(0);
  temp2=analogRead(mmtemp);
temp2=temp2*.48848125;
mtemp=round(temp2);
Serial.print("temp.val=");
 Serial.print(mtemp);
 Serial.write(0xff);                       
  Serial.write(0xff);
  Serial.write(0xff);
  Serial.write("\n");
  delay(0);
  smoke=analogRead(A2);
  Serial.print(smoke);
  
}
