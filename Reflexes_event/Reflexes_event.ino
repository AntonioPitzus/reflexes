
#include "event.h"
#include "button.h"
#include "buttonImpl.h"
#include "Led.h"

int count = 0;
enum {OFF, BLINKING, GO, CORRECT, WRONG} state;

void buttonPressedHandler(Event* ev){
  count = count + 1;
  Serial.println(count);
}


Button* button;

void setup() {
  Serial.begin(9600);
  button = new ButtonImpl(2);
  addEventHandler(BUTTON_PRESSED_EVENT, buttonPressedHandler);  
}

void loop() {
  mainEventLoop();
}
