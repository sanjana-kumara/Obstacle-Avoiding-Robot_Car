#include <Ultrasonic.h>
Ultrasonic u = Ultrasonic(3, 4);  // Trig,Echo

#include <Servo.h>
Servo s = Servo();

int ENA = 11;
int IN1 = 10;
int IN2 = 9;

int ENB = 5;
int IN3 = 7;
int IN4 = 6;

void setup() {

  s.attach(2);  //Servo Pin

  //Motor A

  pinMode(ENA, OUTPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  analogWrite(ENA, 150);

  //Motor B

  pinMode(ENB, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  analogWrite(ENB, 250);

  Serial.begin(9600);  // Serial Monitor
}

void loop() {

  pinMode(8, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(13,OUTPUT);
  

  int x = Serial.read();

  
  // Forward
  if (x == '1') {
    s.write(90);
    delay(300);
    int d = u.read();
    if (d > 20) {
      digitalWrite(IN1, LOW);
      digitalWrite(IN2, HIGH);
      digitalWrite(IN3, LOW);
      digitalWrite(IN4, HIGH);
      digitalWrite(8, HIGH);
      digitalWrite(12,LOW);
      digitalWrite(13, HIGH);
    }
  }

  // Reverse
  if (x == '2') {
    digitalWrite(8, LOW);
    digitalWrite(IN1, HIGH);
    digitalWrite(IN2, LOW);
    digitalWrite(IN3, HIGH);
    digitalWrite(IN4, LOW);
    delay(500);
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, LOW);
    digitalWrite(IN3, LOW);
    digitalWrite(IN4, LOW);
    digitalWrite(12,LOW);
    digitalWrite(13, HIGH);
  }

  // Stop
  if (x == '3') {

    digitalWrite(8, LOW);
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, LOW);
    digitalWrite(IN3, LOW);
    digitalWrite(IN4, LOW);
    digitalWrite(12, HIGH);
    delay(2000);
    digitalWrite(12,LOW);
    digitalWrite(13, HIGH);
  }

  // Turn Right
  if (x == '4') {
    s.write(45);
    delay(300);
    int d = u.read();
    if (d > 20) {
      digitalWrite(8,HIGH);
      digitalWrite(IN1, HIGH);
      digitalWrite(IN2, LOW);
      digitalWrite(IN3, LOW);
      digitalWrite(IN4, HIGH);
      delay(500);
      digitalWrite(IN1, LOW);
      digitalWrite(IN2, LOW);
      digitalWrite(IN3, LOW);
      digitalWrite(IN4, LOW);
      digitalWrite(12,LOW);
      digitalWrite(13, HIGH);
    }
    s.write(90);
    digitalWrite(8,LOW);
  }

  // Trun Left
  if (x == '5') {
    s.write(135);
    delay(300);
    int d = u.read();
    if (d > 20) {
      digitalWrite(8,HIGH);
      digitalWrite(IN1, LOW);
      digitalWrite(IN2, HIGH);
      digitalWrite(IN3, HIGH);
      digitalWrite(IN4, LOW);
      delay(500);
      digitalWrite(IN1, LOW);
      digitalWrite(IN2, LOW);
      digitalWrite(IN3, LOW);
      digitalWrite(IN4, LOW);
      digitalWrite(12,LOW);
      digitalWrite(13, HIGH);
    }
    s.write(90);
    digitalWrite(8,LOW);
  }
 
}
