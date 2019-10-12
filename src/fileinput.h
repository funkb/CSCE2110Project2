#ifndef FILEINPUT_H
#define FILEINPUT_H

#include <vector>
#include <iostream>
#include <string>
#include <regex>
#include <locale>
#include <fstream>
#include "datastructs.h"

using namespace std;

class FileInput{

	private:
		string config_name;
		string input_name;
		int k_min;
		int k_max;
		vector<Point> points;
	public:
		FileInput();

		void parseData();
		void parsePoints();
		void debugLog();

		int getKmin() const;
		int getKmax() const;
		vector<Point> getPoints() const;


};


#endif
