#include <Servo.h>

// This program includes movement of the laser (servo) and rotation of a mirror piece (stepper motor)

// Servo (laser)
Servo servoOne;
int servoOnePin = 5;
int servoButton = 4;
int pos = 0;
int servoOneValue = 0;
int servoValueMax = 360;
int clockwise = 0;

// Stepper (mirror)
int button = 2;
int blue = 8; //(IN 1)
int pink = 9; //(IN 2)
int yellow = 10; //(IN 3)
int orange = 11; //(IN 4)
int currentStep = 0; 

void setup() {
  // Servo
  pinMode(servoButton, INPUT);

  // Stepper
  pinMode(button, INPUT);
  pinMode(blue, OUTPUT);
  pinMode(pink, OUTPUT);
  pinMode(yellow, OUTPUT);
  pinMode(orange, OUTPUT);
  digitalWrite(blue, LOW);
  digitalWrite(pink, LOW);
  digitalWrite(yellow, LOW);
  digitalWrite(orange, LOW);
  Serial.begin(9600);
  servoOne.attach(servoOnePin);
}

void loop() {
  // Button-controlled
  while(digitalRead(servoButton) == 1 && pos < 360) {
    pos++;
    servoOne.write(map(pos,0,360,30,150));
    Serial.println(pos);
    delay(20);
  }
  while(digitalRead(servoButton) == 1 && pos > 0) {
    pos--;
    servoOne.write(map(pos,0,360,30,150));
    delay(20);
  }

  // Stepper
  if (digitalRead(button == 1)) {
    switch (currentStep) {
      case 0:
        digitalWrite(blue, HIGH);
        digitalWrite(pink, LOW);
        digitalWrite(yellow, LOW);
        digitalWrite(orange, LOW);
        break;
        
      case 1:
        digitalWrite(blue, LOW);
        digitalWrite(pink, HIGH);
        digitalWrite(yellow, LOW);
        digitalWrite(orange, LOW);
        break;
        
      case 2:
        digitalWrite(blue, LOW);
        digitalWrite(pink, LOW);
        digitalWrite(yellow, HIGH);
        digitalWrite(orange, LOW);
        break;
        
      case 3:
        digitalWrite(blue, LOW);
        digitalWrite(pink, LOW);
        digitalWrite(yellow, LOW);
        digitalWrite(orange, HIGH);
        break;
    }

    currentStep = (++currentStep < 4) ? currentStep : 0; 
    delay(0);
  } else {
      digitalWrite(blue, LOW);
      digitalWrite(pink, LOW);
      digitalWrite(yellow, LOW);
      digitalWrite(orange, LOW);
  }
}


