int redPin = 13;
int bluePin = 12;
int greenPin = 11;

void setup() {
  // put your setup code here, to run once:
  pinMode(redPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
  pinMode(greenPin, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(redPin, HIGH);
  delay(500);
  digitalWrite(bluePin, HIGH);
  delay(500);
  digitalWrite(greenPin, HIGH);
  delay(500);
  digitalWrite(redPin, LOW);
  digitalWrite(bluePin, LOW);
  digitalWrite(greenPin, LOW);
  delay(500);

  //violet
  // digitalWrite(redPin, HIGH);
  // digitalWrite(bluePin, HIGH);
  // delay(1000);
  // digitalWrite(redPin, LOW);
  // digitalWrite(bluePin, LOW);
  // delay(1000);


}
