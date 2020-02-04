#ifndef __CLICKTASK__
#define __CLICKTASK__

#include "Task.h"
#include "Led.h"

#define DEFAULT_TIME 3000000

class ClickTask: public Task {

  int red;
  int green;
  int blue;
  Led* led;
  bool answer;
  long timer;
  long conta;
  long vstep;
  bool over;
  
public:

  ClickTask(int red, int green, int blue, bool answer, long vstep);  
  void init();  
  void tick();
  bool isOver();
};

#endif

