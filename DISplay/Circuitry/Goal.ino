int photocell = A3;
int photocell2 = A4;
int photocell3 = A5;
int led = 13;

void setup() {
  // put your setup code here, to run once:
  pinMode(photocell, INPUT);
  pinMode(led, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  //delay(500);
  int photocellValue = analogRead(photocell);
  int photocellValue2 = analogRead(photocell2);
  int photocellValue3 = analogRead(photocell3);
  Serial.println(analogRead(photocell2));

  if (photocellValue > 850 || photocellValue2 > 950 || photocellValue3 > 860) {
    digitalWrite(led, HIGH);
  } else {
    digitalWrite(led, LOW);
  }

}
