int switchPin = 2;
int val;
int buttonState;
int buttonPresses = 0;

void setup(){
  pinMode(switchPin, INPUT);

  Serial.begin(9600);
  buttonState = digitalRead(switchPin);
}

void loop(){
  val = digitalRead(switchPin);

  if(val != buttonState){
    if(val == LOW){
      Serial.println("Button just pressed!");
    }
    else{
      Serial.println("Button just released!");
      Serial.print("Button has been pressed ");
      Serial.print(++buttonPresses);
      Serial.println(" times.");
    }
    buttonState = val;
  }

}