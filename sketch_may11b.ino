/*
* Automatic door handle sanitizer
*
* by Chauhan Jainish,
*
*/
#include <Servo.h>

Servo myservo;  // create servo object to control a servo

// defines pins numbers
const int trigPin = 9;
const int echoPin = 10;
// defines variables
long duration;
int distance;
void setup() {
pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
pinMode(echoPin, INPUT); // Sets the echoPin as an Input
myservo.attach(8);  // attaches the servo on pin 9 to the servo object
Serial.begin(9600); // Starts the serial communication
}
void loop() {
// Clears the trigPin
digitalWrite(trigPin, LOW);
delayMicroseconds(2);
// Sets the trigPin on HIGH state for 10 micro seconds
digitalWrite(trigPin, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin, LOW);
// Reads the echoPin, returns the sound wave travel time in microseconds
duration = pulseIn(echoPin, HIGH);
// Calculating the distance
distance= duration*0.034/2;
// Prints the distance on the Serial Monitor
Serial.print("Distance: ");
Serial.println(distance);
if (distance<12){
delay(5000);
myservo.write(0);                  // sets the servo position according to the scaled value
delay(1500);
myservo.write(180);                  // sets the servo position according to the scaled value
delay(1500);
myservo.write(0);                  // sets the servo position according to the scaled value
delay(1500);
}
else{
myservo.write(180);                  // sets the servo position according to the scaled value
delay(15);
}
}
