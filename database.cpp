#include "printables.cpp"
#include <iomanip>
#include <iostream>
#include <string>

using namespace std;

class Item {
public:
  string Description;
  bool isComplete;
  Item() : Description("Empty"), isComplete(false) {}
  Item(string description) : Description(description), isComplete(false) {}
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
  // TODO: add a destructor
};

void DataBase::addItem(Item item) {
  if (!head) {
    head = new Node(item);
    return;
  }
  Node *curr = head;
  while (curr->next) {
    curr = curr->next;
  }
  this->size++;
  curr->next = new Node(item);
}

void DataBase::deleteItem(int index) {
  if (index == 0) {
    deleteHead();
    this->size--;
    return;
  }
  Node *curr = head;
  Node *prev = nullptr;
  int i = 0;
  while (curr && i < index) {
    prev = curr;
    curr = curr->next;
    i++;
  }
  if (!curr) {
    return;
  }
  prev->next = curr->next;
  destroyNode(curr);
  this->size--;
}

void DataBase::deleteHead() {
  if (!head) {
    return;
  }
  Node *delNode = head;
  head = head->next;
  destroyNode(delNode);
}

void DataBase::destroyNode(Node *delNode) {
  delete delNode;
}

void printItem(Item item, int index) {
  cout << index + 1 << ". "
       << "[" << (item.isComplete ? "x" : " ") << "] " << item.Description << endl;
}

void DataBase::displayList() {
  if (!head) {
    printIsEmpty();
    return;
  }
  Node *curr = head;
  int index = 0;
  while (curr) {
    printItem(curr->item, index);
    curr = curr->next;
    index++;
  }
}

void DataBase::toggleItem(int index) {
  Node *curr = head;
  int i = 0;
  while (curr && i < index) {
    curr = curr->next;
    i++;
  }
  if (!curr) {
    return;
  }
  curr->item.isComplete = !curr->item.isComplete;
}

void DataBase::deleteCheckedItems() {
  if (!head) {
    return;
  }
  Node *curr = head;
  Node *prev = nullptr;
  while (curr) {
    if (curr->item.isComplete) {
      if (curr == head) {
        deleteHead();
        curr = head;
        continue;
      }
      prev->next = curr->next;
      destroyNode(curr);
      curr = prev->next;
      continue;
    }
    prev = curr;
    curr = curr->next;
  }
}
