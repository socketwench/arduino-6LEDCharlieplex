
int pinA[] = {1, 0, 2, 2, 1, 0};
int pinB[] = {0, 1, 1, 0, 2, 2};
int pinC[] = {2, 2, 0, 1, 0, 1};
int state = 0;
int maxstate = 5;
int whichWay = 1;

void setup() {
  Serial.begin(9600);
  
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  
  digitalWrite(3, LOW);
  digitalWrite(4, LOW);
  digitalWrite(5, LOW);
}

void loop() {
  if(state > maxstate){
    whichWay = -1;
    state = maxstate - 1;
  }
  else if(state < 0){
    whichWay = 1;
    state = 1;
  }
  
  if(pinA[state] == 1){
    pinMode(3, OUTPUT);
    digitalWrite(3, HIGH);
  }
  else if(pinA[state] == 0){
    pinMode(3, OUTPUT);
    digitalWrite(3, LOW);
  }
  else{
    pinMode(3, INPUT);
    digitalRead(3);
  }
  
  
  if(pinB[state] == 1){
    pinMode(4, OUTPUT);
    digitalWrite(4, HIGH);
  }
  else if(pinB[state] == 0){
    pinMode(4, OUTPUT);
    digitalWrite(4, LOW);
  }
  else{
    pinMode(4, INPUT);
    digitalRead(4);
  }
  
  if(pinC[state] == 1){
    pinMode(5, OUTPUT);
    digitalWrite(5, HIGH);
  }
  else if(pinC[state] == 0){
    pinMode(5, OUTPUT);
    digitalWrite(5, LOW);
  }
  else{
    pinMode(5, INPUT);
    digitalRead(5);
  }
  
  Serial.println(analogRead(A0));  
  delay(analogRead(A0));
  state += whichWay;
}
