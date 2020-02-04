#include "BlinkTask.h"

BlinkTask::BlinkTask(int red, int green, int blue){
  this->red = red;   
  this->green = green;
  this->blue = blue;
}
  
void BlinkTask::init(){
  led = new Led(red, green, blue); 
  state = OFF;    
}
  
void BlinkTask::tick(){
  switch (state){
    case OFF:
      led->switchOrange();
      state = ON; 
      break;
    case ON:
      led->switchOff();
      state = OFF;
      break;
  }
}
