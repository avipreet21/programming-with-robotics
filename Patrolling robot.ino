#include <sparki.h>

void setup() {
  sparki.servo(SERVO_CENTER);

}

void loop() {

  int threshold = 200;

  int edgeLeft = sparki.edgeLeft();
  int lineLeft = sparki.lineLeft();
  int lineCenter = sparki.lineCenter();
  int lineRight = sparki.lineRight();
  int edgeRight = sparki.edgeRight();
  int distance = sparki.ping();
  
  //This tells sparki when to move
  if (lineCenter > 400)
  {
   sparki.moveForward() 
  }

      // This tells sparki to use ultrasonic sensor
    if(distance != -1)
    { 
        if(distance < 20)
        {
          sparki.moveStop();
          for (int i = 0; i < 3; i=i+1)
          {
          sparki.beep();
          }
          delay(100);
        }
    }

   if ( (lineCenter < threshold ) && (lineLeft < threshold) && (lineRight < threshold)&& (edgeLeft < threshold) && (edgeRight < threshold) )
  {
    sparki.moveBackward(3);
    sparki.moveRight(90);
    sparki.moveForward(5);
    sparki.moveRight(90);
    sparki.moveStop();
   }
   delay(500);

  

  

  // This prints the value of the infread sensors
  sparki.clearLCD();

  sparki.print("Edge Left:   ");
  sparki.println(edgeLeft);
 
  sparki.println();
 
  sparki.print("Line Left:   ");
  sparki.println(lineLeft);
 
  sparki.print("Line Center: ");
  sparki.println(lineCenter);
 
  sparki.print("Line Right:  ");
  sparki.println(lineRight);
 
  sparki.println();
 
  sparki.print("Edge Right:  ");
  sparki.println(edgeRight);


 
  sparki.updateLCD();
  delay(100);  
  

}
