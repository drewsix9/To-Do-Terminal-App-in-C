#include "printables.h"

void printHeader() {
  cout << setfill('-') << setw(56) << "" << endl;
  cout << setfill(' ') << setw(33) << "To Do List"
       << "" << endl;
  cout << setfill('-') << setw(56) << "" << endl;
}

void printCommands() {
  cout << setfill('-') << setw(56) << "" << endl;
  cout << "COMMANDS: " << endl;
  cout << "- Type a number to mark/unmark a task as complete" << endl;
  cout << "- 'a' to add a new task" << endl;
  cout << "- 'd' to delete a task" << endl;
  cout << "- 'q' to quit the app" << endl;
  cout << "- 'c' to delete completed tasks" << endl;
  cout << "\nEnter your command: ";
}

void printIsEmpty() {
  cout << "\n\n\n";
  cout << setfill(' ') << setw(33) << "List is Empty"
       << "" << endl;
  cout << "\n\n\n";
}
