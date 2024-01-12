#include "database.h"
#include <filesystem>
#include <fstream>
#include <string.h>
#include <string>

using namespace std;

#ifndef FILEHANDLING_H
#define FILEHANDLING_H

bool fileExists(string fileName);
void saveToFile(string fileName, DataBase &db);
DataBase *loadFromFile(string fileName);

#endif // !FILEHANDLING_H