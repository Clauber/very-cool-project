#include <Arduino.h>
#define red 0
#define green 4
#define blue 5
int t = 3000;
void setup()
{
  // put your setup code here, to run once:
}

void turnRed()
{
  analogWrite(red, 255);
  analogWrite(green, 0);
  analogWrite(blue, 0);
}

void turnGreen()
{
  analogWrite(green, 255);
  analogWrite(red, 0);
  analogWrite(blue, 0);
}

void turnBlue()
{
  analogWrite(blue, 255);
  analogWrite(red, 0);
  analogWrite(green, 0);
}

void turnWhite()
{
  analogWrite(red, 255);
  analogWrite(green, 255);
  analogWrite(blue, 255);
}

void turnOff()
{
  analogWrite(red, 0);
  analogWrite(green, 0);
  analogWrite(blue, 0);
}

void loop()
{
  turnRed();
  delay(t);

  turnGreen();
  delay(t);

  turnBlue();
  delay(t);

  turnWhite();
  delay(t);

  turnOff();
  delay(t);
}
