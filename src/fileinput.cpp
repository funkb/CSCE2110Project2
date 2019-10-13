#include "fileinput.h"

#define DEBUG 1

FileInput::FileInput(){
  cout << "Please enter the name of the configuration file:";
  getline(cin, config_name);
}

void FileInput::parseData(){
  ifstream file;
  vector<string> tempData; //Move data here before cleansing
  string buffer;
  regex reg("[:]");
  smatch m;

  file.open(config_name);

  if(file.fail()){
    cout << "File not found! Aborting..." << endl;
    exit(69);
  }
  while(!file.eof()){
    try{
      getline(file,buffer);
      regex_search(buffer, m,reg); //Check for ':'
      buffer = buffer.substr(m.position(0) + 1); //Cut ':' and all char before
      tempData.push_back(buffer);
    }catch(out_of_range oor){
      break;
    }
  }

  //First 3 lines always the same format/length
  input_name = tempData.at(0);
  input_name.erase(remove_if(input_name.begin(), input_name.end(), ::isspace), input_name.end());
  k_min = stoi(tempData.at(1)); //stoi : str -> int
  k_max = stoi(tempData.at(2));
  debugLog();
  tempData.erase(tempData.begin(), tempData.begin() + 3);
  for(auto it = tempData.begin(); it != tempData.end(); ++it){
    stringstream sstream(*it);
    int token;
    vector<int> tempTok;

    while(sstream >> token){
      tempTok.push_back(token);
      #if DEBUG==1
      cout << "Token: " << token << endl;
      #endif
    }
  }
}

void FileInput::parsePoints(){
  ifstream file;
  string buffer;

  file.open(input_name);

  if(file.fail()){
    cout << "File not found! Aborting..." << endl;
    exit(420);
  }

  while(!file.eof()){
    try{
      Point temp;
      string token;
      vector<string> tempData; //Before cleanse and cast

      getline(file,buffer);
      stringstream sstream(buffer);
      while(sstream >> token){ tempData.push_back(token); }

      temp.uID = stoi(tempData.at(0));
      temp.x = stod(tempData.at(1));
      temp.y = stod(tempData.at(2));
      #if DEBUG==1
        temp.Print();
      #endif
    }catch(out_of_range oor){
      break;
    }
  }
}

void FileInput::debugLog(){
  #if DEBUG==1
    cout << "\n========== Debug Variable Dump ==========" << endl;
    cout << "config_name: " << config_name << endl;
    cout << "input_name: " << input_name << endl;
    cout << "k_min: " << k_min << endl;
    cout << "k_max: " << k_max << endl;
    printVector(points);
    cout << "=========================================\n" << endl;
  #endif
}

void FileInput::printVector(vector<Point> vec){
  cout << "\n========== vec =========" << endl;
  for(auto it = vec.begin(); it != vec.end(); ++it){
    cout << "*it: ";
    *it.Print();
    cout << endl;
  }
  cout << endl;
}
int FileInput::getKmin() const { return k_min; }
int FileInput::getKmax() const { return k_max; }
vector<Point> FileInput::getPoints() const { return points; }
