#ifndef _GARAGEDOOR_CTRL_H_
#define _GARAGEDOOR_CTRL_H_

class Garagedoor_ctrl:
{
public:

    enum Event{ // defining events
        evOpen,
        evClose,
        evStop
    };
    Garagedoor_ctrl(); // Constructor
    void process (Event e); // changing the state based on the event e
    

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
