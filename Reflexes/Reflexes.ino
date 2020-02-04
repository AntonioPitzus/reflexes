#include "Led.h"
#include "ButtonImpl.h"
#include <TimerOne.h>

#define B_1 2
#define B_2 3
#define R 11
#define G 6
#define B 5

enum {ON, BLINKING, OF} state;
enum {RED, GREEN, BLUE, ORANGE,OFF} color;

Led *led;
ButtonImpl* button[2];

void setup() {
  Serial.begin(9600);
  button[0] = new ButtonImpl(B_1);
  button[1] = new ButtonImpl(B_2);
  led = new Led(R,G,B);
  attachInterrupt(digitalPinToInterrupt(B_1), pressed, FALLING);
  attachInterrupt(digitalPinToInterrupt(B_2), pressed, FALLING);
  Timer1.initialize(1000000);
  Timer1.attachInterrupt(getRandom);
}

void getRandom(){
  long timer = random(2000000, 5000000);
  int r = random(0,4);
  switch(r){
    case 0:
      color = RED;
      break;
    case 1:
      color = GREEN;
      break;
    case 2:
      color = BLUE;
      break;
    case 3:
      color = ORANGE;
      break;
  }
  Timer1.setPeriod(timer);
}

void pressed(){
 // noInterrupts();
  switch(color){
    case RED:
      Serial.println("Bravo");
      break;
    case OFF:
      break;
    default:
      Serial.println("Bravo....Coglione");
      break;
      
  }
  if(color != OFF){
    color = OFF;
    Timer1.setPeriod(2500000);
    //Timer1.restart();  
  }
  //interrupts();
}

void loop() {
  switch(color){
    case RED:
      led->switchRed();
      break;
    case GREEN:
      led->switchGreen();
      break;
    case BLUE:
      led->switchBlue();
      break;
    case ORANGE:
      led->switchOrange();
      break;
    case OFF:
      led->switchOff();
      break;
  }
}
