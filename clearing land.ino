#include <sparki.h>
//project2
//last modified 10-25-2022
// author = Avipreet singh

float adistance; // first variable 
float bdistance; // seconnd variable


void setup() {
sparki.servo(0);    // keeps the ultrasonic sensor straight.
timmer();          // function 1 is called here.
}

void loop() {
 
}
// function 1
void timmer()
{
  bool timeron;
  timeron = true; // bool timeron sets true here.
  {
    while (timeron = true) 
    {
     if (millis() >= 120000) // function millis is called here which counts time.
     {
      timeron = false;  // set bool timeron to false if timer counts 3 minutes.
     }else{
      sparkirotation();  // function 2 is called 
     }
    }
  }
}
// function 2
void sparkirotation()  
{
  int counter;
  if (sparki.ping() != -1)  // condition is created here 
  {
    if (sparki.ping() < 20) //another condition is created here, if sparki sees a ball it run the code following code.
    {
     sparki.clearLCD();
     counter= counter + 1;
     sparki.print("Balls =");  // This function prints the word balls = .
     sparki.println(counter);  // This function prints number of balls.
     sparki.updateLCD();
     sparki.moveStop();   // sparki saws a ball stop rotating.
     delay(150);
     adistance = distanceball(); // calling function 3 distanceball and storing the value in the adistance variable.
     delay(150);
     bdistance = blackedgedistance(); // calling the function 4 blackedgdedistance and storing the value in the bdistance variable.
     delay(150);
     
     sparki.moveBackward(adistance + bdistance); // makes sparki move back to the center of the figure
     delay(150);
     }else{
      sparki.moveRight();  // makes sparki rotates if it sees somthing that is more than 20 units away.
      delay(150);
     }
  }else{
    sparki.moveRight();  // makes sparki rotates if it sees nothing.
    delay(150);
  }
}

// function 3
float distanceball() // This function makes sparki to move closer to the ball and close the gripper.
{
  int distance1 = sparki.ping(); // This is the distance between the sparki and the ball.
  sparki.moveForward(distance1); // sparki move in forward direction by distance calculated in above line.
  delay(150);
  sparki.gripperClose();  // gripper close for the 2 seconds.
  delay(2000);
  sparki.gripperStop();
  return distance1;
}

// function 4
float blackedgedistance() // This function makes sparki  to remove the ball out of the figure
{ 
  int distance2 = 0;
  for (distance2 =0; sparki.lineCenter() > 300; distance2 = distance2 + 1) // this calculates the distance travel by the sparki while carrying the ball outside the figure.
  {
    sparki.moveForward(1);
    sparki.moveStop();
  }
  sparki.gripperOpen(); // it opens the gripper for 2 seconds
  delay(2000);
  sparki.gripperStop();
  return distance2;
}

