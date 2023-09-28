//globals
int blinkCheck;
int tempCheck;
long blinkLength;

int turn1 = 11;
int turn2 = 5;

int blinker = 2;

void setup() {
  pinMode(turn1, OUTPUT);
  pinMode(turn2, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);

}

void loop() {
  digitalWrite(turn1, HIGH);
  digitalWrite(turn2, HIGH);
  digitalWrite(4, HIGH);
  digitalWrite(6, HIGH);
  digitalWrite(7, HIGH);
  digitalWrite(8, HIGH);
  digitalWrite(9, HIGH);
  digitalWrite(10, HIGH);

  blinkCheck = digitalRead(blinker);

  if(blinkCheck == LOW){
  
  digitalWrite(turn1, HIGH);
  digitalWrite(turn2, HIGH);
  blinkLength = random(800, 1200);
  Serial.println(blinkLength);
  delay(blinkLength);
  tempCheck = digitalRead(blinker);
  if(tempCheck == LOW){    //checks if switch has flipped mid "cycle"
    digitalWrite(turn1, LOW);
    digitalWrite(turn2, LOW);
  }

  blinkLength = random(800, 1200);
  Serial.println(blinkLength);
  delay(blinkLength);
  
  }
  else {
    digitalWrite(turn1, HIGH);
    digitalWrite(turn2, HIGH);
  }

}

void lightSolid(){
  digitalWrite(turn1, HIGH);
  digitalWrite(turn2, HIGH);
  return;
}
