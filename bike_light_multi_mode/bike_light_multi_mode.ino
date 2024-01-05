int switchPin = 2;
int ledPins[] = {8, 9, 10, 11, 12};
int buttonState;
int curState;
int curState2;
int lightMode = 0;

void turnOffLeds(){
  for(int ledPin: ledPins){
    digitalWrite(ledPin, LOW);
  }
}

void turnOnLeds(){
  for(int ledPin: ledPins){
    digitalWrite(ledPin, HIGH);
  }
}

void blinkLeds(){
  turnOnLeds();
  delay(100);
  turnOffLeds();
  delay(100);
}

void waveLeds(){
  for(int ledPin: ledPins){
    digitalWrite(ledPin, HIGH);
    delay(60);
  }

  for(int ledPin: ledPins){
    digitalWrite(ledPin, LOW);
    delay(60);
  }

}

void bouncingLeds(){
  for(int ledPin: ledPins){
    digitalWrite(ledPin, HIGH);
    delay(60);
  }

  for(int ledPin: ledPins){
    digitalWrite(ledPin, LOW);
    delay(60);
  }

  //bounces back
  for(int i = 4; i >= 0; i--){
    digitalWrite(ledPins[i], HIGH);
    delay(60);    
  }

  for(int i = 4; i >= 0; i--){
    digitalWrite(ledPins[i], LOW);
    delay(60);    
  }
}

void setup() {
  // put your setup code here, to run once:
  pinMode(switchPin, INPUT);
  for (int ledPin: ledPins){
    pinMode(ledPin, OUTPUT);
  }

  buttonState = digitalRead(switchPin);
}

void loop() {
  // put your main code here, to run repeatedly:
  
  curState = digitalRead(switchPin);
  // take a second reading to account for bouncy switches
  delay(10); 
  curState2 = digitalRead(switchPin);

  //when button is pressed, change light state (but only once)
  if((curState != buttonState) && (curState == curState2)){ // when button is pressed, turn on or off
    if(curState == LOW){ // button just pressed
      if(lightMode == 4){
        lightMode = 0;
      } else{
        lightMode++;
      }
    }
    buttonState = curState;
  }

  switch(lightMode){
    case 1:
      turnOnLeds();
      break;
    case 2:
      blinkLeds();
      break;
    case 3:
      waveLeds();
      break;
    case 4:
      bouncingLeds();
      break;
    default:
      turnOffLeds();
  }


}
