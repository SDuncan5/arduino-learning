int ledPinPush = 12;
int ledPinRelease = 11;
int switchPin = 2;
int val;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(ledPinPush, OUTPUT);
  pinMode(ledPinRelease, OUTPUT);
  pinMode(switchPin, INPUT);
}

void loop() {
  // Serial.print("Read switch input: ");
  // Serial.println(digitalRead(switchPin)); // reads value of pin and displays value
  // delay(100);

  val = digitalRead(switchPin);
  // button is being pushed!
  if(val == LOW){
    digitalWrite(ledPinRelease, LOW);
    digitalWrite(ledPinPush, HIGH);
    // digitalWrite(ledPin, HIGH);
    // delay(100);
    // digitalWrite(ledPin, LOW);
    // delay(100);
  }
  else{
    digitalWrite(ledPinPush, LOW);
    digitalWrite(ledPinRelease, HIGH);
  }
}
