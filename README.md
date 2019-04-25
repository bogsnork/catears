# animatronic cat ears

Each ear (Left and Right) has 2 servos, Top and Bottom.  Bottom rotates in horizontal plane, Top rotates in vertical.  

Aim is to use 2 buttons to tell ears to carry out pre-set routines.  A particular button press would make the ears to a particular routine.  Eventually would like about 4 routines, so buttons would need to be multifunctional, e.g. with double-press or long-press alternatives.  Extension project may be to add joystick control.  

Two build options: microbit or Arduino nano.  JavaScript code for https://makecode.microbit.org/#editor in this repository.  Arduino Nano working sketch also in this repository

## Current state Arduino:

Currently the sketch catears.ino does 2 things: 
- on button 1 press, left ear servos do a routine
- on button 2 press, right ear servos do a routine

## Current state microbit
Currently the js script catears_11_microbit.js does 3 things: 
- on button A press, left ear servos do a routine
- on button B press, right ear servos do a routine
- on button A+B press, both ears do a routine


### see wiki for more: https://github.com/bogsnork/catears/wiki
