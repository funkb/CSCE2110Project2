#ifndef DATASTRUCTS_H
#define DATASTRUCTS_H

#include <iostream>

using namespace std;

struct Point{
	int uID;
	double x;
	double y;

	Point() : uID(0), x(0), y(0) {};
	void Print() {
		cout << "uID: " << uID << "\nx: " << x << "\ny: " << y << "\n\n";
	}
};

#endif
