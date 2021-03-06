#include "garagedoor_ctrl.h"

#include <iostream>
using namespace std;


const Garagedoor_ctrl::Transition Garagedoor_ctrl::fsm[] = //defining FSM
{
  {closedState, evBtn, &Garagedoor_ctrl::actionOpening, openingState},
  {openingState, evOpen, &Garagedoor_ctrl::actionOpen, openState},
  {openingState, evBtn, &Garagedoor_ctrl::actionStop, stopOpeningState},
  {openState, evBtn, &Garagedoor_ctrl::actionClosing, closingState},
  {closingState, evClosed, &Garagedoor_ctrl::actionClosed, closedState},
  {closingState, evBtn, &Garagedoor_ctrl::actionStop, stopClosingState},
  {stopOpeningState, evBtn, &Garagedoor_ctrl::actionClosing, closingState},
  {stopClosingState, evBtn, &Garagedoor_ctrl::actionOpening, openingState}
};

Garagedoor_ctrl::Garagedoor_ctrl() :
  currentState(closedState),
  oldState(closedState)
{

}

// process engine which handles the event
void Garagedoor_ctrl::process(Event e)
{
  for (size_t i=0; i < sizeof(fsm) / sizeof(Transition); ++i) // for each row
  {
    if (fsm[i].currentState == currentState &&  fsm[i].ev == e) // is there an entry in the table?
    {
      (this->*fsm[i].pAction)();
      oldState = currentState;
      currentState = fsm[i].nextState;
      break;  // prevent seccondary executions that might occure!
    }
  }
}

void Garagedoor_ctrl::actionClosed(void)
{
  cout <<"Door is closed!"<< endl;
}

void Garagedoor_ctrl::actionClosing(void)
{
  door.close();
}

void Garagedoor_ctrl::actionOpening(void)
{
  door.open();
}

void Garagedoor_ctrl::actionOpen(void)
{
  cout <<"Door is open!" << endl;
}

void Garagedoor_ctrl::actionStop(void)
{
 door.stop();
}
