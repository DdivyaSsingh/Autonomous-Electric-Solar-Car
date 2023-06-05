/*
PROGRAM TERMINOLOGY AND INSTRUCTIONS

in1, in2  => directions of movement of right wheel
in3, in4  => directions of movement of left wheel

enA, enB => speed of rotation of motors

//Move forward
in1 => HIGH
in2 => LOW
in3 => LOW
in4 => HIGH


//Move Backward
in1 => LOW
in2 => HIGH
in3 => HIGH
in4 => LOW

*/

int enA = 2;
int in1 = 1; 
int in2 = 3; 

int enB = 6;
int in3 = 5;
int in4 = 7;

#define MAX 5

void rotate(){
      digitalWrite(in1,LOW); //
      digitalWrite(in2,LOW);
      digitalWrite(in3,LOW);
      digitalWrite(in4,HIGH);
      analogWrite(enA,250);
      analogWrite(enB,250);
}

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


void function(String path){

  int n = path.length();

  for(int i=0;i<n;i++){

      char current = path.charAt(i);

    if(i == 0){

      if(current == 'L'){
        anticlockRotate();
      }
      else if(current == 'R'){
        clockRotate();
      }
      else if(current == 'U'){
        anticlockRotate();
      }

    }

    else if(path.charAt(i) != path.charAt(i-1)){
      
      char previous = path.charAt(i-1);

      if(current == 'U'){
        if(previous == 'L'){
          anticlockRotate();
        }
        else{
          clockRotate();
        }
      }

      else if(current == 'D'){
        if(previous == 'L'){
          clockRotate();
        }
        else{
          anticlockRotate();
        }
      }

      else if(current == 'R'){
        if(previous == 'U'){
          anticlockRotate();
        }
        else
        {
          clockRotate();
        }
      }
      else if(current == 'L'){
      {
        if(previous == 'U'){
          clockRotate();
        }
        else
        {
          anticlockRotate();
        }
      }
      }

    }


    mover();

  }

}

void getallpath(int matrix[MAX][MAX], int n,int row,int col,String cur,String &finalstring,int &minval){
    if(row >= n or col >= n or row<0 or col<0 or matrix[row][col] == 0)
    return ;
    
    if(row == n-1 and col == n-1)
    {
            if(minval == 100000)
            {
                finalstring = cur;
                minval = finalstring.length();
            }
      if(minval!=100000 and cur.length()<minval)
      {
          minval = cur.length();
          finalstring = cur;
      }
    }
    
    //now if its one we have 4 calls
    matrix[row][col] = 0;
    
    getallpath(matrix,n,row-1,col,cur+"U",finalstring,minval);
    getallpath(matrix,n,row,col+1,cur+"R",finalstring,minval);
    getallpath(matrix,n,row,col-1,cur+"L",finalstring,minval);
    getallpath(matrix,n,row+1,col,cur+"D",finalstring,minval);

    matrix[row][col] = 1;
    
    return ;
}

void setup() {
  // put your setup code here, to run once:

    Serial.begin(9600);

    pinMode(enA,OUTPUT);
    pinMode(in1,OUTPUT);
    pinMode(in2,OUTPUT);
    pinMode(enB,OUTPUT);
    pinMode(in3,OUTPUT);
    pinMode(in4,OUTPUT);

    //rotate();
    //mover();

    // put your setup code here, to run once:
    int m[MAX][MAX] = { { 1, 0, 0, 0, 0 },
                        { 1, 1, 1, 1, 1 },
                        { 1, 1, 1, 0, 1 },
                        { 0, 0, 0, 0, 1 },
                        { 0, 0, 0, 0, 1 } };
    
    int n = sizeof(m) / sizeof(m[0]);
    int minval = 100000;
    String finalstring = "";
    getallpath(m,n,0,0,"",finalstring,minval);
    Serial.println(finalstring);

    function(finalstring);
}



void loop() {
  // put your main code here, to run repeatedly:

}
