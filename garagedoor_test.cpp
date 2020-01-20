#include <iostream>
#include "garagedoor_ctrl.h"

using namespace std;

int main(void)
{
  bool end_flag = false;
  char user_input = 0;

  Garagedoor_ctrl door;

  cout << "press e to end the program" << endl;
  cout << "press b to open, close and stop the door" << endl;
  cout << "press o for opened" << endl;
  cout << "press c for closed" << endl;

 do{
    cin >> user_input;

    switch(user_input){
      case 'b': // pushbutton
        door.process(Garagedoor_ctrl::evBtn);
        break;

      case 'o':
        door.process(Garagedoor_ctrl::evOpen);
        break;

      case 'c':
        door.process(Garagedoor_ctrl::evClosed);
        break;

      case 'e': // end program
        end_flag = true;
        break;

      default:
        break;
    }
  }while(!end_flag);

  return 0;
}
