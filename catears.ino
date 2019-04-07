/* CatEars
   by Christoph Kratz and Hanna Kratz
   makes animatronic cat ears move using Arduino Nano
*/

#include <Servo.h>

Servo servoTL;  // create servo objects to control a servo
Servo servoBL;
Servo servoTR;
Servo servoBR;

// constants won't change.
const int button1Pin = 2;     // the number of the pushbutton pin

// variables will change:
int button1State = 0;         // variable for reading the pushbutton status


// twelve servo objects can be created on most boards

int posTL = 60;    // variable to store the servo position and initial value
int posBL = 80;
int posTR = 60;
int posBR = 80;


void setup() {
  servoTL.attach(6);  // attaches the servo on pin 9 to the servo object
  servoBL.attach(7);
  servoTR.attach(8);
  servoBR.attach(9);

  // initialize the pushbutton pin as an input:
  pinMode(button1Pin, INPUT);
}

void loop() {

  // read the state of the pushbutton value:
    button1State = digitalRead(button1Pin);

  // check if the pushbutton is pressed. If it is, the buttonState is HIGH:
    if (button1State == HIGH) {

  //carry out a servo maneuvre for Bottom Left servo
  for (posBL = 0; posBL <= 180; posBL += 1) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    servoBL.write(posBL);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15ms for the servo to reach the position
  }
  for (posBL = 180; posBL >= 0; posBL -= 1) { // goes from 180 degrees to 0 degrees
    servoBL.write(posBL);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15ms for the servo to reach the position
  }

  //carry out a servo maneuvre for Top Left servo
  for (posTL = 0; posTL <= 180; posTL += 1) { 
    servoTL.write(posTL);              
    delay(15);                       
  }
  for (posTL = 180; posTL >= 0; posTL -= 1) { 
    servoTL.write(posTL);              
    delay(15);                       
  }
 }
}
