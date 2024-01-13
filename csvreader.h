#include "database.h"
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

#ifndef CSVREADER_H
#define CSVREADER_H

class CSVreader {
private:
  vector<vector<string>> data;

public:
  CSVreader();
  vector<vector<string>> readCSV(string filename);
  bool isFileExist(string filename);
  DataBase *loadFromFile(string filename);
  void saveToDb(DataBase &db);
  void saveToFile(string filename, DataBase &db);
  bool getBool(vector<string> &line, int index);
  string getString(vector<string> &line, int index);
  ~CSVreader() {}
};

#endif // !CSVREADER_H