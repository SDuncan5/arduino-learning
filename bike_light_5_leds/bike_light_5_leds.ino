int switchPin = 2;
int ledPins[] = {8, 9, 10, 11, 12};
int buttonState;
int curState;
int curState2;
bool lightMode = 0;

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
  delay(7); 
  curState2 = digitalRead(switchPin);

  //when button is pressed, change light state (but only once)
  if((curState != buttonState) && (curState == curState2)){ // when button is pressed, turn on or off
    if(curState == LOW){ // button just pressed
      lightMode = !lightMode;
    }
    buttonState = curState;
  }

  if(lightMode == 1){
    for(int ledPin: ledPins){
     digitalWrite(ledPin, HIGH);
    }

    //making light blinky
    delay(100);

    for(int ledPin: ledPins){
     digitalWrite(ledPin, LOW);
    }
    
    delay(100);

  } else{
    for(int ledPin: ledPins){
      digitalWrite(ledPin, LOW);
    }
  }


  // if(curState == LOW){ // button pushed
  //   for(int ledPin: ledPins){
  //     digitalWrite(ledPin, HIGH);
  //   }
  // }
  // else{
  //   for(int ledPin: ledPins){
  //     digitalWrite(ledPin, LOW);
  //   }
  // }


}
