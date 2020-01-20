#include "garagedoor_ctrl.h"

#include <iostream>
using namespace std;

Garagedoor_ctrl::Garagedoor_ctrl()
{

}
void Garagedoor_ctrl::process(Event e)
{
  for (size_t i=0; i < sizeof(fsm) / sizeof(Transition); ++i) // for each row
  {
    if (fsm[i].currentState == currentState &&  fsm[i].ev == e) // is there an entry in the table?
    {
      (this->*fsm[i].pAction)();
      currentState = fsm[i].nextState;
      break;
    }
  }
}

void Garagedoor_ctrl::actionClosing(void){
  Garagedoor.op

}
