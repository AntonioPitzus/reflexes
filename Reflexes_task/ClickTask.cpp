#include "ClickTask.h"

ClickTask::ClickTask(int red, int green, int blue, bool answer, long vstep){
  this->red = red;   
  this->green = green;
  this->blue = blue;
  this->answer = answer;
  this->vstep = vstep;
  over = false;
}
  
void ClickTask::init(){
  led = new Led(red, green, blue); 
  timer = DEFAULT_TIME;
  conta = 0;
  if(answer){
    led->switchGreen();  
  }
  else{
    led->switchRed();
  }
}

void ClickTask::tick(){
  if(conta < timer){
    conta += vstep;
  }
  else{
    over = true;
  }
}

bool ClickTask::isOver(){
  return over;
}

