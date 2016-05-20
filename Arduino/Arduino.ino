#include <DualMC33926MotorShield.h>
#include <String.h>
#include <avr/pgmspace.h>

DualMC33926MotorShield md;
const unsigned char DISPENSE = 3; // Pin 3 controls dispensing motor
const unsigned char height = 25;
const unsigned char width = 25;
//int y_index = 0;
unsigned char motorSpeed = 110;
//String motor_x_direction;
//String motor_y_direction;
//byte tableValue = 0;
bool tempMatrix[height][width];

// store array onto flash memory since it is 32KB as opposed to 2KB SRAM
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
    else
    {
      Serial.print(F("COMMAND NOT RECOGNIZED: "));
      Serial.println(startInput);
    }
  }

  Serial.println(F("Enter 1, 2, or 3: "));
  Serial.println(F("1. Square"));
  Serial.println(F("2. Triangle"));
  Serial.println(F("2. Smiley Face"));
  char selection;
  while ((selection != '1') && (selection != '2') && (selection != '3'))
  {
    if (Serial.available() > 0)
    {
      selection = Serial.read();
    }
  }
  
  if (selection == '1')
    Serial.println(F("*** Printing square ***"));
  else if (selection == '2')
    Serial.println(F("*** Printing triangle ***"));
  else if (selection == '3')
    Serial.println(F("*** Printing smiley face ***"));
  delay(1000);

  Serial.println(F("Running Following The Shape Algorithm"));

  int printNum = 0;
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
              
          if (tempMatrix[i][j])
          {
              printNum++;
          }
      }
  }
  Serial.print(F("Number of points to print: "));
  Serial.println(printNum);

  unsigned char delayX = 100;
  unsigned char delayY = 180;
  unsigned char currentX = 0;
  unsigned char currentY = 0;
  int tempX = 0;
  int tempY = 0;
  unsigned char xFound[printNum];
  unsigned char yFound[printNum];
  unsigned char index = 0;
  unsigned char found = 0;
  unsigned char offset = 0;
  double distance[printNum];
  double minDistance;
  unsigned char minX;
  unsigned char minY;
  int timeXdelay[printNum];
  int timeYdelay[printNum];
  unsigned char xCoord[printNum];
  unsigned char yCoord[printNum];
  unsigned char printNumIndex = 0;

  // Check if starting point needs to be printed
  // Add it to the need to be printed array if yes
  // If yes, increment printNumIndex
  // If yes, decrement number of points to be printed
  if (tempMatrix[0][0] == 1)
  {
      timeXdelay[printNumIndex] = 0;
      timeYdelay[printNumIndex] = 0;
      xCoord[printNumIndex] = 0;
      xCoord[printNumIndex] = 0;
      printNumIndex++;
      printNum--;
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
      // Store the coordinate value
      timeXdelay[printNumIndex] = (minX - currentX) * delayX;
      timeYdelay[printNumIndex] = (minY - currentY) * delayY;
      xCoord[printNumIndex] = minX;
      yCoord[printNumIndex] = minY;

      // Reset the matrix square printed to 0 so we don't accidentally print it again
      tempMatrix[minX][minY] = 0;

      // Change our current x and y coordinate location to the printed location
      currentX = minX;
      currentY = minY;

      // Increment the index to store our delay
      // Decrement the number of printing to be done
      printNumIndex++;
      printNum--;
  }

  /*
  // Print out the path for the shape
  for (int i = 0; i < printNumIndex; i++)
  {
      Serial.print(i);
      Serial.print(".\t");
      Serial.print(xCoord[i]);
      Serial.print(", ");
      Serial.print(yCoord[i]);
      Serial.print("\t");

      Serial.print("(");
      Serial.print(timeXdelay[i]);
      Serial.print(", ");
      Serial.print(timeYdelay[i]);
      Serial.println(")");
  }*/

  Serial.println(F("Path calculated!"));
  delay(1000);
  Serial.println(F("Printing is starting"));

  for (int i = 0; i < printNumIndex; i++)
  {
      // If time is negative, that means we need to move in the negative direction
      // X direction motor
      if (timeXdelay[i] < 0)
          md.setM1Speed(-motorSpeed);
      else if (timeXdelay[i] > 0)
          md.setM1Speed(motorSpeed);
      // Make we have positive time
      delay(abs(timeXdelay[i]));
      md.setM1Speed(0);
  
      // If time is negative, that means we need to move in the negative direction
      // Y direction motor
      if (timeYdelay[i] < 0)
          md.setM2Speed(-motorSpeed);
      else if (timeYdelay[i] > 0)
          md.setM2Speed(motorSpeed);
      // Make we have positive time
      delay(abs(timeYdelay[i]));
      md.setM2Speed(0);
  
      // Print x & y coordinates
      // Print x & y motor delays
      Serial.print(i);
      Serial.print(F(".\t"));
      Serial.print(xCoord[i]);
      Serial.print(F(","));
      Serial.print(yCoord[i]);
      Serial.print(F("\t"));
      Serial.print(F("("));
      Serial.print(timeXdelay[i]);
      Serial.print(F(", "));
      Serial.print(timeYdelay[i]);
      Serial.print(F(")"));
  
      // Dispense after we have moved into position
      dispense();
  }

  // Calculate how far we are from 0,0
  int resetXMotor = (0 - xCoord[printNumIndex-1]) * delayX;
  int resetYMotor = (0 - yCoord[printNumIndex-1]) * delayY;
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
  Serial.println(F("1P. Y Motor - left"));
  Serial.println(F("1N. Y Motor - right"));
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
