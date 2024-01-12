#include "printables.h"
#include <iomanip>
#include <iostream>
#include <string>

using namespace std;

#ifndef DATABASE_H
#define DATABASE_H
class Item {
public:
  string Description;
  bool isComplete;
  Item() : Description("Empty"), isComplete(false) {}
  Item(string description) : Description(description), isComplete(false) {}
  Item(string description, bool iscomplete) : Description(description), isComplete(iscomplete) {}
  ~Item() {}
  // TODO: add a destructor
};

class DataBase {
private:
  class Node {
  public:
    Item item;
    Node *next;
    Node(Item item) : item(item), next(nullptr) {}
    Node(Item item, Node *next) : item(item), next(next) {}
  };

public:
  int size;
  Node *head;
  DataBase() : size(0), head(nullptr) {}
  int getSize() { return this->size; }
  void addItem(Item item);
  void deleteItem(int index);
  void deleteHead();
  void destroyNode(Node *delNode);
  void displayList();
  void toggleItem(int index);
  bool isInRange(int index) { return (index >= 0 && index <= size); }
  void deleteCheckedItems();
  Item operator[](int index);
  // TODO: add a destructor
};
#endif // !DATABASE_H