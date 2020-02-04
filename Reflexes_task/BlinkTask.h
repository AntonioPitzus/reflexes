#ifndef __BLINKTASK__
#define __BLINKTASK__

#include "Task.h"
#include "Led.h"

class BlinkTask: public Task {

  int red;
  int green;
  int blue;
  Led* led;
  enum { ON, OFF} state;

public:

  BlinkTask(int red, int green, int blue);  
  void init();  
  void tick();
};

#endif

