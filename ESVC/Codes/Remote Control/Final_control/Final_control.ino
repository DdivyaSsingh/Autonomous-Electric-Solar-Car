#include <BluetoothSerial.h>
//#include <Servo_ESP32.h>
#include <ESP32Servo.h>
#if !defined(CONFIG_BT_ENABLED) || !defined(CONFIG_BLUEDROID_ENABLED)
#error Bluetooth is not enabled! Please run `make menuconfig` to and enable it
#endif


static const int servoPin = 2; //printed D13 on the board

Servo servo1;
BluetoothSerial SerialBT;

char val;
int angle;
int a=13;
int br1=4;
int br2=5;
int st1=19;
int st2=22;

int start=12;
void setup() {
  
Serial.begin(115200);       
SerialBT.begin("TEAM DAKSH"); //Bluetooth device name
Serial.println("The device started, now you can pair it with bluetooth!");
servo1.attach(servoPin);

pinMode(a,OUTPUT);
pinMode(br1,OUTPUT);
pinMode(br2,OUTPUT);
pinMode(st1,OUTPUT);
pinMode(st2,OUTPUT);
pinMode(start,OUTPUT);
digitalWrite(a,LOW);
digitalWrite(br1,LOW);
digitalWrite(br2,LOW);
digitalWrite(st1,LOW);
digitalWrite(st2,LOW);
digitalWrite(start,LOW);

}

void loop() {
  if( SerialBT.available() ) {      // if data is available to read
  {
    val = SerialBT.read();// read it and store it in 'val'
     
  }
servo1.write(angle);
switch (val)
{

case 'R':
 digitalWrite(a,HIGH);
 digitalWrite(st2,HIGH);
 SerialBT.print("received R");
 Serial.println("R");
 Serial.println(angle);
 delay(1000);
 digitalWrite(st2,LOW);
 
  break;
case 'L':
 digitalWrite(a,HIGH);
 digitalWrite(st1,HIGH);
 SerialBT.print("received l");
  Serial.println("L");
  Serial.println(angle);
 delay(1000);
 digitalWrite(st1,LOW);
 
  break;
 case 'B':
 digitalWrite(a,HIGH);
 digitalWrite(br1,HIGH);
 SerialBT.print("received B");
  Serial.println("b");
  Serial.println(angle);
 angle=0;
 servo1.write(angle);
 delay(1000);
 digitalWrite(br1,LOW);
 
 
  break;
case 'F':
 digitalWrite(a,HIGH);
 digitalWrite(br2,HIGH);
 servo1.write(angle);
 SerialBT.print("received F");
  Serial.println("F");
  Serial.println(angle);
 delay(1000);
 digitalWrite(br2,LOW);
 
  break;
case 'S':
 digitalWrite(a,LOW);
 digitalWrite(br1,LOW);
 digitalWrite(br2,LOW);
 digitalWrite(st1,LOW);
 digitalWrite(st2,LOW);
 SerialBT.print("received s");
  Serial.println("S");
  Serial.println(angle);
  Serial.println("angle");
  break;
//default:
// angle=0;
// servo1.write(angle);
// digitalWrite(st1,LOW); 
// digitalWrite(st2,LOW);
// digitalWrite(a,LOW);
// 
// break;
// 
// while(1){
// servo1.write(0);
// digitalWrite(st1,LOW); 
// digitalWrite(st2,LOW);
// digitalWrite(a,LOW);
// digitalWrite(br1,LOW);  
// digitalWrite(br2,LOW);
//  }
  
case '0':
  angle=0;
  break;
case '1':
  angle=18;
  break;
case '2':
  angle=36;
  break;
case '3':
  angle=18*3;
  break;
case '4':
  angle=18*4;
  break;
case '5':
  angle=18*5;
  break;
case '6':
  angle=18*6;
  break;
case '7':
  angle=7*18;
  break;
case '8':
  angle=8*18;
  break;
case '9':
  angle=9*18;
case 'q':
  angle=10*18;
  break;
case 'W':
 digitalWrite(start,LOW);
 break;
 case 'w':
 digitalWrite(start,HIGH);
 break;
}
}}
