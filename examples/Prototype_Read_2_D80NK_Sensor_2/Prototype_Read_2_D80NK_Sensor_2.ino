// link HD: https://cdn.sparkfun.com/datasheets/Robotics/How%20to%20use%20a%20quadrature%20encoder.pdf
int QEM [16] = {0,-1,1,2,1,0,2,-1,-1,2,0,1,2,1,-1,0}; // Quadrature Encoder Matrix
//To read the array my index is: Old * 4 + New
//So my code reads like this:
//Old = New;
//New = digitalRead (inputA) * 2 + digitalRead (inputB); // Convert binary input to decimal value
//Out = QEM [Old * 4 + New];

/*

-1
0
-1
0
-1
0
-1
xuong
0

1
0
1
0
1
0
1
len
0



*/

int Old,New,Out;
#define inputA    7
#define inputB    6
void setup() {
  // put your setup code here, to run once:
  pinMode(inputA, INPUT_PULLUP);
  pinMode(inputB, INPUT_PULLUP);
  Serial.begin(9600);
  Serial.println("Start");
}
unsigned long ttt = 0;
int lastOut, lastLastOut = 256, index;
void loop() {
  // put your main code here, to run repeatedly:
  readState();
  if(millis() - ttt >= 10){
    if(lastOut != Out){
      XuLy();
      Serial.println(Out);
      lastOut = Out;
    }
  }
//  delay(50);
}

void readState(){
  Old = New;
  New = digitalRead (inputA) * 2 + digitalRead (inputB); // Convert binary input to decimal value
  Out = QEM [Old * 4 + New];
}


void XuLy(){
  int tempOut;
  if(Out !=0){
    tempOut = Out;
    if(tempOut == -1)lastLastOut = lastLastOut << 1;
    else if (tempOut == 1)lastLastOut = lastLastOut >> 1;

//    Serial.print(tempOut);
//    Serial.print("\t");
//    Serial.print(lastLastOut);
//    Serial.println("=======");  
  }
  
  if((digitalRead (inputA) == 1) && (digitalRead (inputB) == 1)){
//    Serial.print(lastOut);
//    Serial.print("\t");
//    Serial.print(lastLastOut);
//    Serial.print("*****");
    if(lastLastOut == 4096){
      Serial.println("len");
    }else if(lastLastOut == 16){
      Serial.println("xuong");
    }
    index = 0;
    lastLastOut = 256;
  }
}
