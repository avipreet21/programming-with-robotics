#include <Sparki.h>
// include the sparki library



void setup()
{
}



void loop()
{
  MoonBotLeft();
  MoonTopLeft();
  MoonTopRight();
  MoonBotRight();
}

void drawearth(int x, int y)
{
  sparki.clearLCD();
  sparki.drawCircleFilled(60, 32, 5);
  sparki.drawCircleFilled(x, y, 2);
  sparki.updateLCD();
  delay(100);
}

void MoonBotLeft()
{
  int x = 60;
  int y = 12;
  while ( x < 84 && y < 32 ) {
    x = x + 1;
    y = y + 1;
    drawearth(x, y);
  }

}

void MoonTopLeft()
{
  int x = 84;
  int y = 32;
  while ( x > 60 && y < 52 ) {
    x = x - 1;
    y = y + 1;
    drawearth( x,  y);
    delay(100);
  }
}

void MoonTopRight()
{
  int x = 60;
  int y = 52;
  while ( x > 40 && y > 32 ) {
    x = x - 1;
    y = y - 1;
    drawearth( x,  y);
    delay(100);
  }
}

void MoonBotRight()
{
  int x = 40;
  int y = 32;
  while ( x < 60 && y > 12 ) {
    x = x + 1;
    y = y - 1;
    drawearth(x,  y);
    delay(100);
  }
}
