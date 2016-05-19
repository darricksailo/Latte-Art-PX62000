using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace FollowThePath
{
    class Program
    {
        static void Main(string[] args)
        {
            int[,] matrix = {
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

            int resolution = 25;
            int printNum = 0;
            int[,] tempMatrix = new int[resolution, resolution];
            for (int i = 0; i < resolution; i++)
            {
                for (int j = 0; j < resolution; j++)
                {
                    tempMatrix[i, j] = matrix[i, j];
                    if (tempMatrix[i, j] == 1)
                    {
                        printNum++;
                    }
                    Console.Write(tempMatrix[i, j]);
                }
                Console.WriteLine();
            }
            Console.WriteLine("Number of points to print: {0}", printNum);

            int delayX = 100;
            int delayY = 180;
            int currentX = 0;
            int currentY = 0;
            int tempX = 0;
            int tempY = 0;
            int[] xFound = new int[printNum];
            int[] yFound = new int[printNum];
            int index = 0;
            int found = 0;
            int offset = 0;
            double[] distance = new double[printNum];
            double minDistance;
            int minX;
            int minY;
            int[] timeXdelay = new int[printNum];
            int[] timeYdelay = new int[printNum];
            int[] xCoord = new int[printNum];
            int[] yCoord = new int[printNum];
            int printNumIndex = 0;

            // Check if starting point needs to be printed
            // Add it to the need to be printed array if yes
            // If yes, increment printNumIndex
            // If yes, decrement number of points to be printed
            if (tempMatrix[0, 0] == 1)
            {
                timeXdelay[printNumIndex] = 0;
                timeYdelay[printNumIndex] = 0;
                xCoord[printNumIndex] = 0;
                xCoord[printNumIndex] = 0;
                printNumIndex++;
                printNum--;
            }

            Console.WriteLine("Processing...");
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
                        //Console.WriteLine("Checking Location: {0}, {1}", tempX, tempY);
                        // Make sure that we do not go out of bounds
                        if (tempX >= 0 && tempY >= 0 && tempX < resolution && tempY < resolution)
                        {
                            //Console.Write("Current Location: {0}, {1}\t", currentX, currentY);
                            //Console.WriteLine("Checked Location: {0}, {1}", tempX, tempY);
                            // If we found a 1, add the x & y coordinate to the array
                            // Increment the number of 1's found
                            if (tempMatrix[tempX, tempY] == 1)
                            {
                                xFound[index] = tempX;
                                yFound[index] = tempY;
                                index++;
                                found++;
                                //Console.WriteLine("FOUND: {0}, {1}", tempX, tempY);
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
                    //Console.WriteLine();
                }

                // Calculate the distance from the found 1's compared to the current x and y coordinate
                for (int i = 0; i < found; i++)
                {
                    distance[i] = Math.Sqrt(Math.Pow(currentX - xFound[i], 2) + Math.Pow(currentY - yFound[i], 2));
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
                tempMatrix[minX, minY] = 0;

                // Change our current x and y coordinate location to the printed location
                currentX = minX;
                currentY = minY;

                // Increment the index to store our delay
                // Decrement the number of printing to be done
                printNumIndex++;
                printNum--;

                for (int i = 0; i < resolution; i++)
                {
                    for (int j = 0; j < resolution; j++)
                    {
                        Console.Write(tempMatrix[i, j]);
                    }
                    Console.WriteLine();
                }
                Console.WriteLine();
                //System.Threading.Thread.Sleep(200);
            }

            Console.WriteLine("Start:\t0,0");

            for (int i = 0; i < printNumIndex; i++)
            {
                Console.Write("{0}.\t{1}, {2}\t", i, xCoord[i], yCoord[i]);
                Console.WriteLine("({0}, {1})", timeXdelay[i], timeYdelay[i]);
            }

            Console.WriteLine("Reset:\t0,0\t({0},{1})", (0 - xCoord[printNumIndex - 1]) * delayX, (0 - yCoord[printNumIndex - 1]) * delayY);
        }

    }
}
