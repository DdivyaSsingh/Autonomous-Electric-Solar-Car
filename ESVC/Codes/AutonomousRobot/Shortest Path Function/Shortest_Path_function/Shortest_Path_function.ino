#define MAX 5

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

}

void loop() {
  // put your main code here, to run repeatedly:

}
