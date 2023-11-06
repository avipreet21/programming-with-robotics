#include <sparki.h>
void setup() {

  sparki.clearLCD();    //clears LCD

  for(int j=0;j<3;j++)  // loop that works 3 times getting new letter each time
  {
    int readings[8];
    int chara;
    scanplates(readings); // function1 is called here
    chara = decimalnumber(readings, 8); // function 2 is called here
    char letter = ' '; // assigning letter variable to empty
    letter = char(chara);//converting ascii number  to its ascii number character 
    sparki.println(letter);//printing the new letter in next line.
    sparki.updateLCD();//Updating sparki's LCD with new letter
  }
}


void loop() {

}

//function1
void scanplates(int data[]) // this function moves sparki forward and stores the value of the sensor in the array data.
{
   for(int i =0; i < 8; i++)  // loop is created to take 8 readings.
  {
    sparki.moveForward(1.3); // move 1 unit forward
    delay(4000);
    if (sparki.lineCenter() < 600)
    {
     data[i] = 1;  // if the tile is black then store value 1
    }else{
     data[i] = 0; // if the tile is white than store the value 0
    }
    delay(100);
  }
}

//function2
int decimalnumber(int data[], int number) //This function converts the binary number to the decimal number
{
  int value = 1;
  int deci = 0;  
  int pos = 8;
  for(int i = 0; i < number; i++) // loop is created here
  {
   deci = data[pos]*value + deci; // formulas to convert the binary numbers to the decimal number.
   value = value*2;
   pos = pos - 1;
  }
  return deci; // returns the decimal number
}


