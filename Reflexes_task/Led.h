#ifndef __LED__
#define __LED__

class Led{ 
public:
  Led(int red, int green, int blue);
  void switchOff(); 
  void switchGreen();
  void switchRed();
  void switchBlue();
  void switchOrange();   
private:
  int green;
  int red;
  int blue; 
};

#endif
