#ifndef _GARAGEDOOR_CTRL_H_
#define _GARAGEDOOR_CTRL_H_

#include "garagedoor.h"

class Garagedoor_ctrl
{
public:

    enum Event{ // defining events
        evBtn, // Button pressed
        evOpen,
        evClosed
    };
    Garagedoor_ctrl(); // Constructor
    void process (Event e); // changing the state based on the event e

private:
  enum State{
    openingState,
    openState,
    closingState,
    closedState,
    stopOpeningState,
    stopClosingState
  };

  // holds the current state of the FSM
  State currentState;
  State oldState;

  // action functions
  void actionClosing(void);
  void actionClosed(void);
  void actionOpening(void);
  void actionOpen(void);
  void actionStop(void);
  void actionStopTransistion(void);

  // function ptr for action function
  typedef void (Garagedoor_ctrl::*Action)(void);

  struct Transition
  {
    State currentState;   // current state
    Event ev;             // event triggering the transition
    Action pAction;       // pointer to action function
    State nextState;      // next state
  };
  static const Transition fsm[];
  // the door
  Garagedoor door;
};

#endif
