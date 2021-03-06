#include <Servo.h> //Servos library


Servo Servo_X; //Servo object
Servo Servo_Y; //Servo object

const int PIN_Joystick_X_In = A0 ; //joystick input from analogue pins
const int PIN_Joystick_Y_In = A1 ;

int Val_X,Val_Y; //Stores the values to set the servo
float Joystick_X,Joystick_Y,Div; //X,Y feeds from joystick and denominator

void setup() {
  Servo_X.attach(5) ; // Attach the Servo controller to pin 5
  Servo_Y.attach(6) ; // Attach the Servo controller to pin 6
  Serial.begin(9600); //Set up the serial

  Div = float(analogRead(PIN_Joystick_X_In) * 2) / 180; //Set the demoninator based on the measured middle resistance val 
  //Output some stuff
  Serial.print("Setting Div to: ");
  Serial.print(Div,DEC);
  Serial.print("\n");
}

void loop() {

  //Trial of joystick stuff
  

  Joystick_X = analogRead(PIN_Joystick_X_In); //Get the X val
  Joystick_Y = analogRead(PIN_Joystick_Y_In); //Get the Y val

  Val_X = Joystick_X / Div; //Calculate the maximum X
  Val_Y = Joystick_Y / Div; //Calculate the maximum Y
  
  Serial.print("X: ");
  Serial.print(Joystick_X,DEC);
  Serial.print(" Y:");
  Serial.print(Joystick_Y,DEC);
  Serial.print(" Set Servo X to:");
  Serial.print(Val_X,DEC);
  Serial.print(" Set Servo Y to:");
  Serial.print(Val_Y,DEC);
  Serial.print("\n");

  Servo_X.write(Val_X); //Write the value to the servo
  Servo_Y.write(Val_Y); //Write the value to the servo

  delay(50); //Quick delay

}
