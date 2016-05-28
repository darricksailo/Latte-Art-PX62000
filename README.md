# Latte Art PX62000

This is our senior project at Cal Poly Pomona. The objective of this project is to create a machine that will draw an image on the latte foam's surface.

The hardware was designed and created from scratch, with many of the concepts and implementations inspired from x-y plotters and 3D printers. We decided to use the Arduino Uno as our microcontroller board for this project.

A program, written in C#, was created to take in an image, crop to center with a square shape, convert the image to black and white, and provide the Arduino Uno with a binary lookup table. 0 would indicate white, while 1 would indicate black.

Our Arduino Uno uses the binary lookup table to determine when and where the dispenser needs to dispense the liquid to. We also use a form of a shortest path algorithm for a more efficient and quicker print as opposed to how an inkjet printer would print (the print head would move back and forth while the paper slides out).

#### Main Menu
![Latte Art PX62000 Main Menu](http://darrickteng.github.io/Images/Latte-Art-PX62000/MainMenu.png)

#### Print Options
![Latte Art PX62000 Print Options](http://darrickteng.github.io/Images/Latte-Art-PX62000/Print.png)

#### Move Function Operation
![Latte Art PX62000 Move Function Operation](http://darrickteng.github.io/Images/Latte-Art-PX62000/Move.png)