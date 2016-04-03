#include <DualMC33926MotorShield.h>
#include <String.h>
DualMC33926MotorShield md;

const int goPin = 2;    // Pin 2 to start printing
int goValue = 1;
const int DISPENSE = 3; // Pin 3 for dispensing
const int height = 25;
const int width = 25;
int x_index = 0;
String motor_x_direction;
String motor_y_direction;
int pictureMatrix[25][25] = {
  {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, 
  {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, 
  {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, 
  {0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0}, 
  {0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0}, 
  {0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0}, 
  {0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0}, 
  {0, 0, 0, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 0, 0, 0}, 
  {0, 0, 0, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 0, 0, 0}, 
  {0, 0, 0, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 0, 0, 0}, 
  {0, 0, 0, 1, 1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 0, 0, 0}, 
  {0, 0, 0, 1, 1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 0, 0, 0}, 
  {0, 0, 0, 1, 1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 0, 0, 0}, 
  {0, 0, 0, 1, 1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 0, 0, 0}, 
  {0, 0, 0, 1, 1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 0, 0, 0}, 
  {0, 0, 0, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 0, 0, 0}, 
  {0, 0, 0, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 0, 0, 0}, 
  {0, 0, 0, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 0, 0, 0}, 
  {0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0}, 
  {0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0}, 
  {0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0}, 
  {0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0}, 
  {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, 
  {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, 
  {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
};

void setup()
{
  // initialize serial connection at 115,200 bits/sec or 14,400 bytes/sec
  Serial.begin(115200);
  Serial.println("Latte Art PX62000");

  // initialize pin modes and timer 1 for dual motor driver
  md.init();

  pinMode(goPin, INPUT);
  pinMode(DISPENSE, OUTPUT);
}

void loop()
{
  // wait for the push button to be pressed before we start the printing
  waitForGo();

  // setSpeeds(int m1Speed, int m2Speed)
  // Motor 1 = x direction
  // Motor 2 = y direction
  md.setSpeeds(0, 0);                             // Set both motors to stop moving
  motor_x_direction = "right";                    // Using a string to let us know which direction motor is moving
  motor_y_direction = "down";

  x_index = 0;
  for (int i = 0; i < height; i++)
  {
    for (int j = 0; j < width; j++)
    {
      // if look up table is 1, activate the dispenser
      if (pictureMatrix[x_index][i] == 1)
      {
        dispense();
      }

      // increment or decrement the look up table x_index depending on motor direction
      // move x direction motor right or left by 1 "pixel"
      if (motor_x_direction == "right")
      {
        x_index++;
        md.setM1Speed(100);
        delay(100);
        md.setM1Speed(0);
      }
      else if (motor_x_direction == "left")
      {
        x_index--;
        md.setM1Speed(-100);
        delay(100);
        md.setM1Speed(0);
      }

      // if we reach the end of the picture, change motor direction
      // since we are drawing the image zigzag
      if (x_index == 0)
        motor_x_direction = "right";
      else if (x_index == 300)
        motor_x_direction = "left";
    }

    // move the y direction motor down 1 "pixel"
    md.setM2Speed(100);
    delay(100);
    md.setM2Speed(0);
  }
}

// *** Waiting for the GO signal *** //
void waitForGo()
{
  goValue = digitalRead(goPin);     // Read go pin value
  while (goPin == HIGH)
  {
    delay(100);                     // Wait 100 ms before checking go pin value again
    goValue = digitalRead(goPin);   // Re-read go pin value
  }
}

// *** Dispense Caramel *** //
void dispense()
{
  digitalWrite(DISPENSE, HIGH);   // Set voltage of output pin to high to activate dispenser
  delay (100);                    // Dispense liquid for only 100 ms
  digitalWrite(DISPENSE, LOW);    // Stop dispensing liquid
}

/*
  const int PWM=5;            //Pin5 PWM
  const int DISPENSE=12;      //Pin12 DISPENSE
  const int AMD1=35;          //Motor A1 orientation
  const int AMD2=36;          //Motor A2 orientation
  const int BMD1=6;           //Motor B1 orientation
  const int BMD2=7;           //Motor B2 orientation


  //Motor Functions:
  //AMD1: || AMD2:  || PWM: || Mode:
  //  L   ||  H     || H    || CCW
  //  H   ||  L     || H    || CW
  //  L   ||  L     || H/L  || Stop
  //  H   ||  H     || H/L  || Stop




  void setup() {
  // put your setup code here, to run once:
  pinMode(PWM, OUTPUT);
  pinMode(DISPENSE, OUTPUT);






  }


  void loop() {
  // put your main code here, to run repeatedly:
  int Speed = 255;



  }
*/
