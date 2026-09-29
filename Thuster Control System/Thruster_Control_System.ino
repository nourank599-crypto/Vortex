#include<Servo.h>
byte servoPin=9;
byte potentiometerPin=A0;
Servo servo;
void setup() {
 servo.attach(servoPin);
 //intializing speedcontrol and stop the thruster(Arming signal)
 servo.writeMicroseconds(1500);
 delay(7000);
}

void loop() {
  int potVal=analogRead(potentiometerPin);
  //map potval to PWM
  int pwmVal=map(potVal,0,1023,1100,1900);
  //send signal to ESC
  servo.writeMicroseconds(pwmVal);
  delay(15);
}
