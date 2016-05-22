#include <DualMC33926MotorShield.h>
#include <String.h>
#include <avr/pgmspace.h>

DualMC33926MotorShield md;
const unsigned char DISPENSE = 3; // Pin 3 controls microdispenser
const unsigned char height = 25;
const unsigned char width = 25;
const unsigned char motorSpeed = 110;
const unsigned char delayX = 100;
const unsigned char delayY = 180;
bool tempMatrix[height][width];

// Store array onto flash memory since it is 32KB as opposed to 2KB SRAM
//SQUARE
const bool pictureFirstMatrix[height][width] PROGMEM = {
  {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, 
  {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, 
  {0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0}, 
  {0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0}, 
  {0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0}, 
  {0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0}, 
  {0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0}, 
  {0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0}, 
  {0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0}, 
  {0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0}, 
  {0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0}, 
  {0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0}, 
  {0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0}, 
  {0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0}, 
  {0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0}, 
  {0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0}, 
  {0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0}, 
  {0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0}, 
  {0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0}, 
  {0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0}, 
  {0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0}, 
  {0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0}, 
  {0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0}, 
  {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, 
  {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
};

//TRIANGLE
const bool pictureSecondMatrix[height][width] PROGMEM = {
  {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, 
  {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, 
  {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, 
  {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, 
  {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0}, 
  {0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0}, 
  {0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0}, 
  {0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0}, 
  {0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0}, 
  {0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0}, 
  {0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0}, 
  {0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0}, 
  {0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0}, 
  {0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0}, 
  {0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0}, 
  {0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0}, 
  {0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0}, 
  {0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0}, 
  {0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0}, 
  {0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0}, 
  {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1}, 
  {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1}, 
  {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, 
  {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, 
  {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1} 
};

//SMILEY FACE
const bool pictureThirdMatrix[height][width] PROGMEM = {
  {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, 
  {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, 
  {0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0}, 
  {0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0}, 
  {0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0}, 
  {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, 
  {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, 
  {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, 
  {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, 
  {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, 
  {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, 
  {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, 
  {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, 
  {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, 
  {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, 
  {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, 
  {0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0}, 
  {0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0}, 
  {0, 0, 0, 0, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 0, 0, 0}, 
  {0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0}, 
  {0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0}, 
  {0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0}, 
  {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, 
  {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, 
  {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
};

//STAR
const bool pictureFourthMatrix[height][width] PROGMEM = {
  {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, 
  {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, 
  {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, 
  {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, 
  {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, 
  {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, 
  {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, 
  {0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, 
  {0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0}, 
  {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}, 
  {1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0}, 
  {0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0}, 
  {0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0}, 
  {0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0}, 
  {0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0}, 
  {0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0}, 
  {0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0}, 
  {0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0}, 
  {0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0}, 
  {0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 1, 1, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0}, 
  {0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 1, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0}, 
  {0, 0, 0, 0, 0, 1, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0}, 
  {0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0}, 
  {0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0}, 
  {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
};

//DEATHLY HALLOWS SYMBOL
const bool pictureFifthMatrix[height][width] PROGMEM = {
  {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, 
  {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, 
  {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, 
  {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, 
  {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, 
  {0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 1, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0}, 
  {0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0}, 
  {0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 1, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0}, 
  {0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0}, 
  {0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 1, 1, 1, 1, 1, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0}, 
  {0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0}, 
  {0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 1, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0}, 
  {0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0}, 
  {0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0}, 
  {0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0}, 
  {0, 0, 0, 1, 1, 1, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 1, 1, 1, 0, 0, 0}, 
  {0, 0, 0, 1, 1, 1, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 1, 1, 1, 0, 0, 0}, 
  {0, 0, 1, 1, 0, 1, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 1, 0, 1, 1, 0, 0}, 
  {0, 0, 1, 0, 0, 1, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 1, 0, 0, 1, 0, 0}, 
  {0, 1, 1, 0, 0, 0, 1, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 1, 0, 0, 0, 1, 1, 0}, 
  {0, 1, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 1, 0}, 
  {1, 1, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 1, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 1, 1}, 
  {1, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 1}, 
  {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}, 
  {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}
};
  
void setup()
{
  // initialize serial connection at 115,200 bits/sec or 14,400 bytes/sec
  Serial.begin(115200);
  // F() function means that the strings will be stored in flash instead of SRAM
  Serial.println(F("Latte Art PX62000"));

  // initialize pin modes and timer 1 for dual motor driver
  md.init();
  // setSpeeds(int m1Speed, int m2Speed)
  md.setSpeeds(0, 0);                             // Set both motors to stop moving

  pinMode(DISPENSE, OUTPUT);
  digitalWrite(DISPENSE, LOW);
}

void loop()
{
  // wait for the push button to be pressed before we start the printing
  Serial.println(F("Waiting for input..."));
  Serial.println(F("Available Commands: 'print', 'move', 'dispense', 'superdispense'"));
  String startInput = "";
  while (startInput != "print")
  {
    while (Serial.available() == 0);
    if (Serial.available() > 0);
    {
      startInput = Serial.readString();
    }
    
    if (startInput == "move")
    {
      Serial.println(startInput);
      moveMotors();
      Serial.println();
    }
    else if (startInput == "dispense")
    {
      Serial.println(startInput);
      for (int i = 0; i < 50; i++)
      {
        dispense();
      }
      Serial.println();
    }
    else if (startInput == "superdispense")
    {
      Serial.println(startInput);
      for (int i = 0; i < 200; i++)
      {
        superdispense();
      }
      Serial.println();
    }
    else if (startInput != "print")
    {
      Serial.print(F("COMMAND NOT RECOGNIZED: "));
      Serial.println(startInput);
    }
  }

  Serial.println(F("1. Square"));
  Serial.println(F("2. Triangle"));
  Serial.println(F("3. Smiley Face"));
  Serial.println(F("4. Star"));
  Serial.println(F("5. Deathly Hallows Symbol"));
  Serial.println(F("6. Custom Image"));
  char selection;
  while ((selection != '1') && (selection != '2') && (selection != '3') && (selection != '4') && (selection != '5') && (selection != '6'))
  {
    while (Serial.available() == 0);
    if (Serial.available() > 0)
    {
      selection = Serial.read();
    }
  }

  int printNum = 0;
  String tempCustomValue;
  if (selection == '1')
    Serial.println(F("*** Printing square ***"));
  else if (selection == '2')
    Serial.println(F("*** Printing triangle ***"));
  else if (selection == '3')
    Serial.println(F("*** Printing smiley face ***"));
  else if (selection == '4')
    Serial.println(F("*** Printing star ***"));
  else if (selection == '5')
    Serial.println(F("*** Printing deathly hallows symbol ***"));
  else if (selection == '6')
  {
    Serial.println(F("Please enter custom image's array into serial monitor"));
    Serial.println(F("The picture should be a 25x25 array or 625 characters"));
    while (Serial.available() == 0);
    Serial.println(F("Reading input...please wait a moment"));
    Serial.println(F("Please do not forget the stopping delimiter at the end: ;!;STOP;!;"));
    while (!tempCustomValue.endsWith(";!;STOP;!;"))
    {
        while (Serial.available() == 0);
        tempCustomValue += (char) Serial.read();
    }

    while (tempCustomValue.length() != 635)
    {
        tempCustomValue = "";
        Serial.println(F("Incorrect input. Please enter 625 characters"));
        while (Serial.available() == 0);
        Serial.println(F("Reading input...please wait a moment"));
        Serial.println(F("Please do not forget the stopping delimiter at the end: ;!;STOP;!;"));
        while (!tempCustomValue.endsWith(";!;STOP;!;"))
        {
            while (Serial.available() == 0);
            tempCustomValue += (char) Serial.read();
        }
    }

    Serial.println(F("*** Printing custom image ***"));
    delay(1000);
    Serial.println(F("Printing is starting"));
    
    int customNum = 0;
    for (int i = 0; i < width; i++)
    {
      for (int j = 0; j < height; j++)
      {
        if (tempCustomValue.charAt(customNum) == '0')
          tempMatrix[i][j] = 0;
        else if (tempCustomValue.charAt(customNum) == '1')
          tempMatrix[i][j] = 1;
        else
          tempMatrix[i][j] = 0;
          
        Serial.print(tempMatrix[i][j]);
        customNum++;
        if (tempMatrix[i][j])
        {
            printNum++;
        }
      }
      Serial.println();
    }
  }
  
  if (selection != '6')
  {
    delay(1000);
    Serial.println(F("Printing is starting"));
    for (int i = 0; i < width; i++)
    {
        for (int j = 0; j < height; j++)
        {
            if (selection == '1')
                tempMatrix[i][j] = pgm_read_byte_near(&pictureFirstMatrix[i][j]);
            else if (selection == '2')
                tempMatrix[i][j] = pgm_read_byte_near(&pictureSecondMatrix[i][j]);
            else if (selection == '3')
                tempMatrix[i][j] = pgm_read_byte_near(&pictureThirdMatrix[i][j]);
            else if (selection == '4')
                tempMatrix[i][j] = pgm_read_byte_near(&pictureFourthMatrix[i][j]);
            else if (selection == '5')
                tempMatrix[i][j] = pgm_read_byte_near(&pictureFifthMatrix[i][j]);
  
            Serial.print(tempMatrix[i][j]);
            if (tempMatrix[i][j])
            {
                printNum++;
            }
        }
        Serial.println();
    }
  }
  Serial.print(F("Number of points to print: "));
  Serial.println(printNum);
  delay(1000);

  unsigned char currentX = 0;
  unsigned char currentY = 0;
  int tempX = 0;
  int tempY = 0;
  unsigned char xFound[24];
  unsigned char yFound[24];
  unsigned char index = 0;
  unsigned char found = 0;
  unsigned char offset = 0;
  double distance[24];
  double minDistance;
  unsigned char minX;
  unsigned char minY;
  int timeXdelay;
  int timeYdelay;
  unsigned char printNumIndex = 0;

  // Check if starting point needs to be printed
  // If yes, increment printNumIndex
  // If yes, decrement number of points to be printed
  // If yes, dispense
  if (tempMatrix[0][0] == 1)
  {
      printNumIndex++;
      printNum--;
      Serial.print(F("1.\t0,0\t(0,0)\t"));
      dispense();
  }

  // Keep iterating until all printing is done
  while (printNum != 0)
  {
      // Reset xFound/yFound index
      // Reset the number of found 1's
      // Reset the offset number for finding 1's
      index = 0;
      found = 0;
      offset = 0;
      
      // Keep looking until we find at least one 1
      while (found == 0)
      {
          /*
          00 01 02
          07    03
          06 05 04
          
          00 01 02 03 04
          15          05
          14          06
          13          07
          12 11 10 09 08
           
          00 01 02 03 04 05 06 
          23                07
          22                08
          21                09  
          20                10  
          19                11  
          18 17 16 15 14 13 12  
          */

          // Start from top left of adjacent squares to look at
          tempX = currentX - 1 - offset;
          tempY = currentY - 1 - offset;
          // Search the adjacent squares of the matrix to current x & y coordinate location
          for (int i = 0; i < 8 * (offset + 1); i++)
          {
              // Make sure that we do not go out of bounds
              if (tempX >= 0 && tempY >= 0 && tempX < width && tempY < height)
              {
                  // If we found a 1, add the x & y coordinate to the array
                  // Increment the number of 1's found
                  if (tempMatrix[tempX][tempY])
                  {
                      xFound[index] = tempX;
                      yFound[index] = tempY;
                      index++;
                      found++;
                  }
              }

              // Increment/decrement x or y index for adjacent square to look at
              if (tempX == (currentX - 1 - offset) && tempY != (currentY + 1 + offset))
              {
                  tempY++;
              }
              else if (tempY == (currentY + 1 + offset)  && tempX != (currentX + 1 + offset))
              {
                  tempX++;
              }
              else if (tempX == (currentX + offset + 1) && tempY != (currentY - 1 - offset))
              {
                  tempY--;
              }
              else if (tempY == (currentY - offset - 1))
              {
                  tempX--;
              }
          }
          // Increase our range of searching by 1 if we do not find any 1's
          offset++;
      }

      // Calculate the distance from the found 1's compared to the current x and y coordinate
      for (int i = 0; i < found; i++)
      {
          distance[i] = sqrt(pow(currentX - xFound[i], 2) + pow(currentY - yFound[i], 2));
      }

      // Find which point has the shortest distance
      minDistance = distance[0];
      minX = xFound[0];
      minY = yFound[0];
      for (int i = 1; i < found; i++)
      {
          if (minDistance > distance[i])
          {
              minDistance = distance[i];
              minX = xFound[i];
              minY = yFound[i];
          }
      }

      // Store the amount of delay for x and y direction to get to that point
      timeXdelay = (minX - currentX) * delayX;
      timeYdelay = (minY - currentY) * delayY;

      // Reset the matrix square printed to 0 so we don't accidentally print it again
      tempMatrix[minX][minY] = 0;

      // Change our current x and y coordinate location to the printed location
      currentX = minX;
      currentY = minY;

      // Increment the index that counts how many we have printed
      // Decrement the number of printing to be done
      printNumIndex++;
      printNum--;

      // Print x & y coordinates
      // Print x & y motor delays
      Serial.print(printNumIndex);
      Serial.print(F(".\t"));
      Serial.print(minX);
      Serial.print(F(","));
      Serial.print(minY);
      Serial.print(F("\t"));
      Serial.print(F("("));
      Serial.print(timeXdelay);
      Serial.print(F(", "));
      Serial.print(timeYdelay);
      Serial.print(F(")"));
      
      // If time is negative, that means we need to move in the negative direction
      // X direction motor
      if (timeXdelay < 0)
          md.setM1Speed(-motorSpeed);
      else if (timeXdelay > 0)
          md.setM1Speed(motorSpeed);
      // Make we have positive time
      delay(abs(timeXdelay));
      md.setM1Speed(0);
  
      // If time is negative, that means we need to move in the negative direction
      // Y direction motor
      if (timeYdelay < 0)
          md.setM2Speed(-motorSpeed);
      else if (timeYdelay > 0)
          md.setM2Speed(motorSpeed);
      // Make we have positive time
      delay(abs(timeYdelay));
      md.setM2Speed(0);
  
      // Dispense after we have moved into position
      dispense();
  }

  // Calculate how far we are from 0,0
  int resetXMotor = (0 - currentX) * delayX;
  int resetYMotor = (0 - currentY) * delayY;
  Serial.print(F("Reset:\t0,0\t"));
  Serial.print(F("("));
  Serial.print(resetXMotor);
  Serial.print(F(","));
  Serial.print(resetYMotor);
  Serial.println(F(")"));
  
  // Move X motor back to 0
  if (resetXMotor < 0)
      md.setM1Speed(-motorSpeed);
  else if (resetXMotor > 0)
      md.setM1Speed(motorSpeed);
  // Make we have positive time
  delay(abs(resetXMotor));
  md.setM1Speed(0);

  // Move Y motor back to 0
  if (resetYMotor < 0)
      md.setM2Speed(-motorSpeed);
  else if (resetYMotor > 0)
      md.setM2Speed(motorSpeed);
  // Make we have positive time
  delay(abs(resetYMotor));
  md.setM2Speed(0);
  Serial.println(F("Printing Completed"));
}

// *** Dispense Caramel *** //
void dispense()
{
  digitalWrite(DISPENSE, HIGH);
  delay(250);
  digitalWrite(DISPENSE, LOW);
  delay(250);
  Serial.println(F("\tDISPENSE"));
}

void superdispense()
{
  digitalWrite(DISPENSE, HIGH);
  delay(50);
  digitalWrite(DISPENSE, LOW);
  delay(100);
  Serial.println(F("SUPER DISPENSE DONE"));
}

// *** Manually move the motors through the serial monitor *** //
void moveMotors()
{
  Serial.println(F("Enter 1 or 2 and then P or N"));
  Serial.println(F("1P. Y Motor - right"));
  Serial.println(F("1N. Y Motor - left"));
  Serial.println(F("2P. X Motor - down"));
  Serial.println(F("2N. X Motor - up"));
  String selection;
  while ((selection != "1P") && (selection != "1N") && (selection != "2P") && (selection != "2N"))
  {
    while (Serial.available() == 0);
    if (Serial.available() > 0)
    {
      selection = Serial.readString();
    }
  }

  Serial.println(F("Enter a movement delay"));
  String selection2;
  unsigned int moveDelay;
  while (selection2.toInt() <= 0)
  {
    while (Serial.available() == 0);
    if (Serial.available() > 0)
    {
      selection2 = Serial.readString();
    }
  }
  moveDelay = selection2.toInt();
  Serial.print(F("Moving delay is "));
  Serial.println(moveDelay);
  
  if (selection == "1P")
  {
    md.setM2Speed(200);
  }
  else if (selection == "1N")
  {
    md.setM2Speed(-200);
  }
  else if (selection == "2P")
  {
    md.setM1Speed(200);
  }
  else if (selection == "2N")
  {
    md.setM1Speed(-200);
  }
  delay(moveDelay);
  md.setSpeeds(0, 0);
  Serial.println(F("Moving Completed"));
}
