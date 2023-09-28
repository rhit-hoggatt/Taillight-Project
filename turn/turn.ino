//libraries
#include <List.hpp>

//globals
int blinkCheck;
int tempCheck;
long blinkLength;

int turn1 = 11;
int turn2 = 5;

int blinker = 2;

List<int> pinControl(false);

void setup() {
  pinControl.add(4);
  pinControl.add(6);
  pinControl.add(7);
  pinControl.add(8);
  pinControl.add(9);
  pinControl.add(10);


  pinMode(turn1, OUTPUT);
  pinMode(turn2, OUTPUT);

  for(int i = 0; i < pinControl.getSize(); i++){
    pinMode(pinControl.getValue(i), OUTPUT);
  }
}

void loop() {
  digitalWrite(turn1, HIGH);
  digitalWrite(turn2, HIGH);

  for(int i = 0; i < pinControl.getSize(); i++){
    digitalWrite(pinControl.getValue(i), HIGH);
  }

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
