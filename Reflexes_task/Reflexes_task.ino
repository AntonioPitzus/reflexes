#include "Led.h"
#include "ButtonImpl.h"
#include "BlinkTask.h"
#include "ClickTask.h"
#include <TimerOne.h>


#define DEFAULT_STEP 250000
#define B_1 2
#define B_2 3
#define R 11
#define G 6
#define B 5

enum {GO, BLINKING, END} state;

Led *led;
BlinkTask btask(R,G,B);
ClickTask* clickTask;
ButtonImpl* button[2];
int score_1;
int score_2;
long timer;
long count;

void setup() {
  score_1 = 0;
  score_2 = 0;
  Serial.begin(9600);
  button[0] = new ButtonImpl(B_1);
  button[1] = new ButtonImpl(B_2);
  led = new Led(R,G,B);
  btask.init();
  attachInterrupt(digitalPinToInterrupt(B_1), button1_action, FALLING);
  attachInterrupt(digitalPinToInterrupt(B_2), button2_action, FALLING);
  Timer1.initialize(DEFAULT_STEP);
  Timer1.attachInterrupt(timerTick);
  state = BLINKING;
}

long switchToBlinking(){
  timer = random(2000000,5000000);
  state = BLINKING;
  count = 0;
}

void timerTick(){
  long timer = random(2000000, 5000000);
  switch(state){
    case BLINKING:
      btask.tick();
      if(count < timer){
         count += DEFAULT_STEP;
      }
      else{
        state = GO;
      }
     case END:
      clickTask->tick();
      break;
  }
}

void button1_action(){
  noInterrupts();
  pressed(1);
  interrupts();
}

void button2_action(){
  noInterrupts();
  pressed(2);
  interrupts();
}

void pressed(int n){
    switch(state){
      case BLINKING:
        if(n == 1){
          score_1--;
          Serial.println("Errore: punteggio giocatore 1 attuale: ");
          Serial.println(score_1);
        }
        else if (n == 2){
          score_2--;
          Serial.println("Errore: punteggio giocatore 2 attuale: ");
          Serial.println(score_2);
        }
        clickTask = new ClickTask(R,G,B,false,DEFAULT_STEP);
        clickTask->init();
        state = END;
        break;
      case GO:
         if(n == 1){
          score_1++;
          Serial.println("Bravo: punteggio giocatore 1 attuale: ");
          Serial.println(score_1);
        }
        else if (n == 2){
          score_2++;
          Serial.println("Bravo: punteggio giocatore 2 attuale: ");
          Serial.println(score_2);
        }
        clickTask = new ClickTask(R,G,B,true,DEFAULT_STEP);
        clickTask->init();
        state = END;
        if (score_1 > 4) {
          Serial.println("Giocatore 1 vincitore della partita");
          score_1 = 0;
          score_2 = 0;
        }
        if (score_2 > 4) {
          Serial.println("Giocatore 2 vincitore della partita");
          score_1 = 0;
          score_2 = 0;
        }
        break;
      case END:
        break;
  }
}

void loop() {
  switch(state){
    case GO:
      led->switchBlue();
      break;
    case END:
      if(clickTask->isOver()){
        switchToBlinking();
      }
  }
  
}
