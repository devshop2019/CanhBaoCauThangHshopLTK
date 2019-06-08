enum{
  _IN_STATE_ = 0b00000010,
  _OUT_STATE_ = 0b00000001,
  _MID_STATE_ = 0b00000000,
  _IDLE_STATE_ = 0b00000011
};
#define pin1  2
#define pin2  3

byte byte_pinState = 0;
byte byte_lastPinState = 0;

void setup() {
  // put your setup code here, to run once:
  pinMode(pin1, INPUT_PULLUP);
  pinMode(pin2, INPUT_PULLUP);
  Serial.begin(9600);
  Serial.println("Start");
  
}

void loop() {
  // put your main code here, to run repeatedly:
  readPinState();
//  Serial.println(byte_pinState, BIN);
  delay(100);
}

void readPinState(){
  byte_pinState = digitalRead(pin1);
  byte_pinState += digitalRead(pin2)<<1;
  stateProcess();
}

void stateProcess(){
  switch (byte_pinState){
    case _MID_STATE_:
    Serial.println("O giua");
    break;
    case _OUT_STATE_:
//    Serial.println("cb ngoai active");
    
    if(byte_lastPinState == _MID_STATE_){
      Serial.println("*****Dang ra ngoai*****");
      byte_lastPinState = _IDLE_STATE_;
    }else;
    
    break;
    case _IDLE_STATE_:
//    Serial.println("khong co gi");
    break;
    case _IN_STATE_:
//    Serial.println("cb trong active");

    if(byte_lastPinState == _MID_STATE_){
      Serial.println("=====Dang vao trong=======");
      byte_lastPinState = _IDLE_STATE_;
    }else;
    
    break;
  }

  if((byte_lastPinState != byte_pinState) && (byte_pinState != _IDLE_STATE_)){
    byte_lastPinState = byte_pinState;
  }
  
}

