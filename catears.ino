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
const int button1Pin = 4;     // the number of the pushbutton pin
const int button2Pin = 3;

// variables will change:
int button1State = 0;        // variable for reading the pushbutton status
int button2State = 0;

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
  pinMode(button2Pin, INPUT);

  // initialize builtin LED as output
  pinMode(LED_BUILTIN, OUTPUT);

}

void loop() {

  // read the state of the pushbutton value:
  button1State = digitalRead(button1Pin);
  button2State = digitalRead(button2Pin);

  // check if the pushbutton is pressed. If it is, the buttonState is HIGH:
  if (button1State == HIGH) {

    // flash light to confirm button press
    digitalWrite(LED_BUILTIN, HIGH);   // turn the LED on (HIGH is the voltage level)
    delay(1000);                       // wait for a second
    digitalWrite(LED_BUILTIN, LOW);    // turn the LED off by making the voltage LOW


    //carry out a servo maneuvre for Top Left servo
    for (posTL = 60; posTL <= 180; posTL += 1) {
      servoTL.write(posTL);
    }
    for (posTL = 180; posTL >= 60; posTL -= 1) {
      servoTL.write(posTL);
      delay(15);
    }

    //carry out a servo maneuvre for Bottom Left servo
    for (posBL = 80; posBL <= 180; posBL += 1) { // goes from 0 degrees to 180 degrees
      // in steps of 1 degree
      servoBL.write(posBL);              // tell servo to go to position in variable 'pos'
      delay(15);                       // waits 15ms for the servo to reach the position
    }
    for (posBL = 180; posBL >= 80; posBL -= 1) { // goes from 180 degrees to 0 degrees
      servoBL.write(posBL);              // tell servo to go to position in variable 'pos'
      delay(15);                       // waits 15ms for the servo to reach the position
    }

  }
   /* I think what you are doing here is fine, I would be tempted here to us "else if" for putting servos relating to button1state to
   some other position if == LOW. Eg. your return positions when the pin goes low could be put in the else if rather than the whole
   sequensce running on one button push perhaps.
   Then use a new "if" statement to determine state for button2state.
   I would be tempted, rather than write each action here for each button push, to build separte functions for the control of the
   servos TL, BL,TR, BR, which were passed variables from the button pushing code. Should half the ammount
   of overall code and allow you to write more complex senarios for multiple button pushes more easily. Build these below where
   void loop(); finishes and then call them form in the Void loop(); part.
   some stuff on the internet about it such as this http://forum.arduino.cc/index.php?topic=1881.0
      
   */
   
   
  else if (button2State == HIGH) {
    digitalWrite(LED_BUILTIN, HIGH);   // turn the LED on (HIGH is the voltage level)
    delay(1000);                       // wait for a second
    digitalWrite(LED_BUILTIN, LOW);    // turn the LED off by making the voltage LOW

    for (posTR = 60; posTR <= 0; posTR -= 1) {
      servoTR.write(posTR);
      delay(15);
    }
    for (posTR = 0; posTR >= 60; posTR += 1) {
      servoTR.write(posTR);
      delay(15);
    }

    //carry out a servo maneuvre for Bottom Right servo
    for (posBR = 80; posBR <= 0; posBR -= 1) { // goes from 0 degrees to 180 degrees
      // in steps of 1 degree
      servoBR.write(posBR);              // tell servo to go to position in variable 'pos'
      delay(15);                       // waits 15ms for the servo to reach the position
    }
    for (posBR = 0; posBR >= 80; posBR += 1) { // goes from 180 degrees to 0 degrees
      servoBR.write(posBR);              // tell servo to go to position in variable 'pos'
      delay(15);                       // waits 15ms for the servo to reach the position
    }
  }

//  else {
//    digitalWrite(LED_BUILTIN, HIGH);   // turn the LED on (HIGH is the voltage level)
//    delay(250);                       // wait for a second
//    digitalWrite(LED_BUILTIN, LOW);    // turn the LED off by making the voltage LOW
//  }
}
