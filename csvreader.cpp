#include "csvreader.h"

CSVreader::CSVreader() {
  data = vector<vector<string>>();
}

vector<vector<string>> CSVreader::readCSV(string filename) {
  vector<vector<string>> res;
  ifstream inputfile(filename.c_str());
  string line;
  while (getline(inputfile, line)) {
    stringstream ss(line);
    vector<string> words;
    string word;
    while (getline(ss, word, ',')) {
      words.push_back(word);
    }
    line = "";
    res.push_back(words);
  }
  inputfile.close();
  return res;
}

bool CSVreader::isFileExist(string filename) {
  ifstream testfile;
  testfile.open(filename.c_str());
  if (!testfile.is_open()) {
    return false;
  }
  testfile.close();
  return true;
}

DataBase *CSVreader::loadFromFile(string filename) {
  if (!isFileExist(filename)) { // if file does not exist, return an empty database
    DataBase *db = new DataBase();
    return db;
  }
  data = readCSV(filename);
  DataBase *db = new DataBase();
  saveToDb(*db);
  return db;
}

void CSVreader::saveToDb(DataBase &db) {
  int _size = 0;
  for (auto line : data) {
    db.addItem(Item(getString(line, 0), getBool(line, 1)));
    _size++;
  }
  db.size = _size;
}

void CSVreader::saveToFile(string filename, DataBase &db) {
  ofstream writefile;
  writefile.open(filename.c_str(), ios::out);
  if (!writefile.is_open()) {
    printf("Error opening file.\n");
    exit(1);
  }
  for (int i = 0; i < db.getSize(); i++) {
    writefile << db[i].Description << "," << db[i].isComplete << endl;
  }
  writefile.close();
}

bool CSVreader::getBool(vector<string> &line, int index) {
  return (line[index] == "1") ? true : false;
}

string CSVreader::getString(vector<string> &line, int index) {
  return line[index];
}
