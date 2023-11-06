//author = avipreet,robin

#include<Sparki.h>

void setup() {
  whiteboard(); //function 1 is called here
  int readings[8]; // A variable array named readings which will contain 8 readings.
  int darkest;  // variable darkest which will store the value of the darkest plate.
  scancolors(readings);  //function3 is called here
  darkest = findarkest(readings, 8);  // function4 is called here
  sparki.clearLCD(); // wipe the screen
 
  sparki.print("darkest readings: "); // show center darkest on screen
  sparki.println(darkest);
 
 
  sparki.updateLCD(); // display all of the information written to the screen
  movetodarkest(darkest); // function5 is called here
}

void loop() {

}


//Function1
int average(unsigned int numberofReadings) // This function calculates the accurate value of the line sensor.
{
  float result = 0;  // A variable result is given value 0.
  for(unsigned int i = 0; i < numberofReadings; i++) //loop is created here 
  {
    result += sparki.lineCenter(); //addition to the values of the line center sensor of each loop
    delay(20);
  }
  return result/numberofReadings; // average value is return by the function
}


//Function2
void whiteboard()   // function finds the white board and stops.
{
  bool foundwhite;  // bool functionwhite is creatd here.
  foundwhite = true; // It is set to the true.
  
  while (foundwhite == true)  //condition is created here that it only runs until bool is true.
  {
    float light = average(4);  // function average is called here which gives an accurate vale of the line sensor.
    if ( light >= 981)     // if the value of the sensor is less than 985 which is white then proceed with following code.
    {
      sparki.moveStop();  // command sparki to stop.
      foundwhite = false;  //set the bool to the false.
    }else{
      sparki.moveForward(1); // unless the condition is met keep sparki moving 1 unit.
      delay(1000);
     }
   } 
}


//function3
void scancolors(int data[]) // this function moves sparki backward and stores the value of the sensor in the array data.
{
   for(int i =0; i < 8; i++)  // loop is created to take 8 readings.
  {
    data[i] = average(4);  // value of the sensor stored on each position of the array.
    sparki.moveBackward(2); // move 2 unit backward.
    delay(1000);
  }
}


//function4
int findarkest(int data[], int number) //This function takes all the values from array and return the largest value.
{
  int max = data[0];  // max variable is set to arrays first position.
  for(int i = 1; i < number; i++) // loop is created here
  {
    if (data[i] < max)  // until the value is less then the last value move to next position
    {
      max = data[i];
    }
  }
  return max; // returns the maximum value
}


//function5
void movetodarkest(int dis)// This function move sparki to the darkest plate.
{
  bool stopper; //bool is set here
  stopper = true;
  while (stopper == true ) 
  {
    float light = average(4); // function average is called here
    delay(100);
    if (light == dis)
    {
      sparki.moveStop(); // if the plate is darkest one then stop
      stopper == false;
    }else{
      sparki.moveForward(2); //move sparki 2 units.
      delay(2000);
    }
  }
}

