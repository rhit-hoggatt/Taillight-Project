//globals
int blinkCheck;
int tempCheck;
long blinkLength;

//outputs
int yellow1 = 50;
int red1 = 52;
int red2 = 48;
int red3 = 44;

//inputs
int blinker = 23;

void setup() {
  Serial.begin(57600);
  Serial.println("Begin Serial");

  //initialize pins
  pinMode(yellow1, OUTPUT);
  pinMode(red1, OUTPUT);
  pinMode(red2, OUTPUT);
  pinMode(red3, OUTPUT);
  pinMode(blinker, INPUT);
}

void loop() {
  digitalWrite(red1, HIGH);
  digitalWrite(red2, HIGH);
  digitalWrite(red3, HIGH);

  blinkCheck = digitalRead(blinker);

  if(blinkCheck == HIGH){
  
  digitalWrite(yellow1, HIGH);
  blinkLength = random(800, 1200);
  delay(blinkLength);
  tempCheck = digitalRead(blinker);
  if(tempCheck == HIGH){    //checks if switch has flipped mid "cycle"
    digitalWrite(yellow1, LOW);
  }

  blinkLength = random(800, 1200);
  delay(blinkLength);
  
  }
  else {
    digitalWrite(yellow1, HIGH);
  }
}

void lightSolid(){
  digitalWrite(yellow1, HIGH);
  return;
}
