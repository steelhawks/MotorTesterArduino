#include <Servo.h>
 
Servo esc;
int throttlePin = 0;
 
void setup()
{
  Serial.begin(9600);
  esc.attach(7);
}
 
void loop()
{ 
  //esc.write(90);
  int throttle = analogRead(throttlePin);
  throttle = map(throttle, 0, 1023, 0, 180);
  esc.write(throttle);
  Serial.println(throttle);
}

/*
#include <Servo.h>

int escPin = 7;
int throttlePin = 0;

int pulse = 0;
int highus = 1500;
int lowus = 1000;

void setup() {
    Serial.begin(9600);
    pinMode(escPin, OUTPUT);
    digitalWrite(escPin, LOW);
}

void loop() {
    digitalWrite(escPin, HIGH);
    delayMicroseconds(highus);
    digitalWrite(escPin, LOW);
    delayMicroseconds(lowus);

    highus = 5 * map(analogRead(throttlePin), 0, 1023, -100, 100) + 1500;
    lowus = 1000;
    Serial.println(analogRead(throttlePin));
}
 */
