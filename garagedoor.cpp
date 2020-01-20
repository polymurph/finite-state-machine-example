#include <iostream>
#include "garagedoor.h"

using namespace std;

Garagedoor::Garagedoor()
{

}

void Garagedoor::open()
{
  cout << "Garagedoor: opening..." << endl;
}

void Garagedoor::close()
{
  cout << "Garagedoor: closing..." << endl;
}

void Garagedoor::stop()
{
  cout << "Garagedoor: stopped!" << endl;
}
