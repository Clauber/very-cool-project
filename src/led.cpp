#include "led.h"

// LED Setup
#define red 14
#define green 0
#define blue 16

// Color changing functions
void turnRed()
{
  analogWrite(red, 255);
  analogWrite(green, 0);
  analogWrite(blue, 0);
}

void turnYellow()
{
  analogWrite(red, 255);
  analogWrite(green, 255);
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

// State options
enum StateOptions
{
  RED,
  BLUE,
  YELLOW,
  GREEN,
  OFF
};

StateOptions state = OFF;

// Setter
void onStateChange(String newState)
{
  newState.toUpperCase();
  StateOptions tempState = OFF;
  if (newState == "RED")
  {
    tempState = RED;
    turnRed();
  }
  else if (newState == "BLUE")
  {
    tempState = BLUE;
    turnBlue();
  }
  else if (newState == "YELLOW")
  {
    tempState = YELLOW;
    turnYellow();
  }
  else if (newState == "GREEN")
  {
    tempState = GREEN;
    turnGreen();
  }
  else if (newState == "OFF")
  {
    turnOff();
  }
  state = tempState;
};

// Getter
String getLEDState()
{
  if (state == RED)
  {
    return "RED";
  }
  else if (state == BLUE)
  {
    return "BLUE";
  }
  else if (state == YELLOW)
  {
    return "YELLOW";
  }
  else if (state == GREEN)
  {
    return "GREEN";
  }
  else
  {
    return "OFF";
  }
}

void ledBegin()
{
  turnOff();
}