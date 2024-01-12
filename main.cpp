#include "database.h"
#include "fileHandling.h"
#include "printables.h"
#include <cassert>
#include <iostream>
#include <string>

using namespace std;

void addTask(DataBase &db);
void deleteTask(DataBase &db);

int main() {
  string filename("todo.csv");
  DataBase *db = loadFromFile(filename);
  string input;
  char choice;
  while (1) {
    system("cls");
    printHeader();
    db->displayList();
    printCommands();
    cin >> choice;
    if (isdigit(choice) && db->isInRange(choice - '0' - 1)) {
      db->toggleItem(choice - '0' - 1);
    } else if (choice == 'a') {
      addTask(*db);
    } else if (choice == 'd') {
      deleteTask(*db);
    } else if (choice == 'q') {
      return 0;
    } else if (choice == 'c') {
      db->deleteCheckedItems();
    } else {
      cout << "\nInvalid Input\n";
    }
    saveToFile(filename, *db);
  }
}

string getUserInput() {
  string input;
  getline(cin, input);
  while (input.empty() || input.size() > 49) {
    getline(cin, input);
  }
  return input;
}

void addTask(DataBase &db) {
  string input;
  cout << "\nEnter a description for the new task: ";
  input = getUserInput();
  db.addItem(Item(input));
}

void deleteTask(DataBase &db) {
  int index;
  cout << "\nEnter the index of the task you want to delete: ";
  cin >> index;
  db.deleteItem(index - 1);
}
