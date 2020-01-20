#ifndef _GARAGEDOOR_CTRL_H_
#define _GARAGEDOOR_CTRL_H_

class Garagedoor_ctrl:
{
public:

  Garagedoor_ctrl()
private:
  enum State{
    openingState,
    openState,
    closingState,
    closedState,
    stopState
  };

  // holds the current state of the FSM
  State currentState;

}

#endif
