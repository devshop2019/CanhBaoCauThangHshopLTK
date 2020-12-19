// link HD: https://cdn.sparkfun.com/datasheets/Robotics/How%20to%20use%20a%20quadrature%20encoder.pdf
int QEM [16] = {0,-1,1,2,1,0,2,-1,-1,2,0,1,2,1,-1,0}; // Quadrature Encoder Matrix
//To read the array my index is: Old * 4 + New
//So my code reads like this:
//Old = New;
//New = digitalRead (inputA) * 2 + digitalRead (inputB); // Convert binary input to decimal value
//Out = QEM [Old * 4 + New];

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
int lastOut;
void loop() {
  // put your main code here, to run repeatedly:
  readState();
  if(millis() - ttt >= 100){
    if(lastOut != Out){
      lastOut = Out;
      Serial.println(Out);
    }
  }
}

void readState(){
  Old = New;
  New = digitalRead (inputA) * 2 + digitalRead (inputB); // Convert binary input to decimal value
  Out = QEM [Old * 4 + New];
}
