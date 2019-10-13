#include "datastructs.h"


Point::Point() : uID(0), x(0), y(0) { }

void Point::Print() {
  cout << "uID: " << uID << "\nx: " << x << "\ny: " << y << "\n\n";
}
