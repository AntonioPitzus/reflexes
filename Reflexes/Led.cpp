#include "Led.h"
#include "Arduino.h"

Led::Led(int red, int green, int blue){
  this->green = green;
  this->red = red;
  this->blue = blue;
  pinMode(this->green,OUTPUT);
  pinMode(this->red,OUTPUT);
  pinMode(this->blue,OUTPUT);
}


void Led::switchOff(){
  digitalWrite(this->green,LOW);
  digitalWrite(this->red,LOW);
  digitalWrite(this->blue,LOW);
};

void Led::switchGreen(){
    analogWrite(this->green,255);  
    analogWrite(this->red,0); 
    analogWrite(this->blue,0); 
}

void Led::switchRed(){
    analogWrite(this->green,0);  
    analogWrite(this->red,255); 
    analogWrite(this->blue,0); 
}

void Led::switchBlue(){
    analogWrite(this->green,0);  
    analogWrite(this->red,0); 
    analogWrite(this->blue,255); 
}

void Led::switchOrange(){
    analogWrite(this->green,120);  
    analogWrite(this->red,237); 
    analogWrite(this->blue,6); 
}
