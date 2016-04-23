#include <DualMC33926MotorShield.h>
#include <String.h>
#include <avr/pgmspace.h>

DualMC33926MotorShield md;
const int DISPENSE = 3; // Pin 3 controls dispensing motor
const int height = 25;
const int width = 25;
int x_index = 0;
int motorSpeed = 200;
String motor_x_direction;
String motor_y_direction;
byte tableValue = 0;

// store array onto flash memory since it is 32KB as opposed to 2KB SRAM
//SQUARE
const boolean pictureSquareMatrix[width][height] PROGMEM = {
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

//HOLLOW HEART
const boolean pictureCircleMatrix[width][height] PROGMEM = {
  {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, 
  {0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0}, 
  {0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0}, 
  {0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0}, 
  {0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0}, 
  {0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0}, 
  {0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, 
  {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0}, 
  {0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, 
  {0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1}, 
  {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1}, 
  {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1}, 
  {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, 
  {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, 
  {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1}, 
  {0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1}, 
  {0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, 
  {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, 
  {0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0}, 
  {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0}, 
  {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, 
  {0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, 
  {0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0}, 
  {0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0}, 
  {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0}
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
  Serial.println(F("Waiting for input to start printing. Type 'print'"));
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
    }
    else if (startInput == "dispense")
    {
      Serial.println(startInput);
      for (int i = 0; i < 10; i++)
      {
        dispense();
      }
    }
  }

  Serial.println(F("Enter 1 or 2: "));
  Serial.println(F("1. Square"));
  Serial.println(F("2. Heart"));
  char selection;
  while ((selection != '1') && (selection != '2'))
  {
    if (Serial.available() > 0)
    {
      selection = Serial.read();
    }
  }
  
  if (selection == '1')
    Serial.println(F("*** Printing square ***"));
  else if (selection == '2')
    Serial.println(F("*** Printing heart ***"));
  delay(1000);

  //waitForGo();
  Serial.println(F("Printing is starting"));

  // Motor 1 = x direction
  // Motor 2 = y direction
  motor_x_direction = "right";                    // Using a string to let us know which direction motor is moving
  motor_y_direction = "down";

  x_index = 0;
  for (int i = 0; i < height; i++)
  {
    for (int j = 0; j < width; j++)
    {
      // makes sure we move to the next line properly
      // for example, (24,0) becomes (24,1) and not (25,1) or (23, 1)
      // and (0,1) becomes (0,2) and not (1,2)
      if (x_index == -1)
        x_index = 0;
      if (x_index == width)
        x_index = width - 1;

      Serial.print(x_index);
      Serial.print(F(" , "));
      Serial.print(i);
      // if look up table is 1, activate the dispenser
      if (selection == '1')
      {
        if (pgm_read_byte_near(&pictureSquareMatrix[x_index][i]))
        //if (pictureSquareMatrix[x_index][i] == 1)
        {
            tableValue = 1;
            dispense();
        }
        else
        {
          tableValue = 0;
          Serial.println();
        }
      }
      else if (selection == '2')
      {
        if (pgm_read_byte_near(&pictureCircleMatrix[x_index][i]))
        //if (pictureCircleMatrix[x_index][i] == 1)
        {
            tableValue = 1;
            dispense();
        }
        else
        {
          tableValue = 0;
          Serial.println();
        }
      }
      else
      {
        tableValue = 0;
        Serial.println();
      }

      // increment or decrement the look up table x_index depending on motor direction
      // move x direction motor right or left by 1 "pixel"
      if (motor_x_direction == "right")
      {
        x_index++;
        md.setM1Speed(motorSpeed);
      }
      else if (motor_x_direction == "left")
      {
        x_index--;
        md.setM1Speed(-motorSpeed);
      }
      delay(50);
       
      if (tableValue == 1)
      {
        md.setM1Speed(0);
        delay(100);
      }

      // if we reach the end of the picture, change motor direction
      // since we are drawing the image zigzag
      if (x_index == -1)
        motor_x_direction = "right";
      else if (x_index == width)
        motor_x_direction = "left";
    }

    // move the y direction motor down 1 "pixel"
    md.setM2Speed(motorSpeed);
    delay(100);
    md.setM2Speed(0);
    delay(100);
  }
  // move motors back to initial position
  md.setM1Speed(0);
  md.setM2Speed(-motorSpeed);
  delay(5000);
  md.setM2Speed(0);
  delay(100);
  Serial.println(F("Printing Completed"));
}

// *** Dispense Caramel *** //
void dispense()
{
  delay(50);
  digitalWrite(DISPENSE, HIGH);
  delay(25);
  digitalWrite(DISPENSE, LOW);
  delay(50);
  Serial.println(F("\tDISPENSE"));
}

// *** Manually move the motors through the serial monitor *** //
void moveMotors()
{
  Serial.println(F("Enter 1 or 2 and then P or N"));
  Serial.println(F("1P. X Motor - right"));
  Serial.println(F("1N. X Motor - left"));
  Serial.println(F("2P. Y Motor - down"));
  Serial.println(F("2N. Y Motor - up"));
  String selection;
  while ((selection != "1P") && (selection != "1N") && (selection != "2P") && (selection != "2N"))
  {
    while (Serial.available() == 0);
    if (Serial.available() > 0)
    {
      selection = Serial.readString();
    }
  }
  
  if (selection == "1P")
  {
    md.setM1Speed(200);
  }
  else if (selection == "1N")
  {
    md.setM1Speed(-200);
  }
  else if (selection == "2P")
  {
    md.setM2Speed(200);
  }
  else if (selection == "2N")
  {
    md.setM2Speed(-200);
  }
  delay(500);
  md.setSpeeds(0, 0);
  Serial.println(F("Moving Completed"));
}

