#include "fileHandling.h"
#include <filesystem>

bool fileExists(string fileName) {
  ifstream testfile;
  testfile.open(fileName.c_str());
  if (!testfile.is_open()) {
    return false;
  }
  return true;
}

void saveToFile(string fileName, DataBase &db) {
  ofstream writefile;
  writefile.open(fileName.c_str(), ios::out);
  if (!writefile.is_open()) {
    fprintf(stderr, "Error opening file.\n");
    exit(1);
  }
  for (int i = 0; i <= db.getSize(); i++) {
    writefile << db[i].Description << "," << db[i].isComplete << endl;
  }
  writefile.close();
}

DataBase *loadFromFile(string fileName) {
  if (!fileExists(fileName)) {
    DataBase *db = new DataBase();
    return db;
  }
  ifstream readfile;
  readfile.open(fileName.c_str());
  if (readfile.fail()) {
    fprintf(stderr, "Error opening file.\n");
    exit(1);
  }
  DataBase *db = new DataBase();
  char *bufferDescription;
  bool bufferIsComplete;
  char bufferLine[50];
  int _size = 0;
  while (readfile.getline(bufferLine, 50)) {
    bufferDescription = strtok(bufferLine, ",");
    string bufferDescriptionCpp(bufferDescription);
    bufferIsComplete = (strtok(nullptr, ",") == "1");
    db->addItem(Item(bufferDescriptionCpp, bufferIsComplete));
    _size++;
  }
  db->size = _size;
  return db;
}
