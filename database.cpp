#include "database.h"

using namespace std;

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

Item DataBase::operator[](int index) {
  Node *curr = head;
  int i = 0;
  while (curr && i < index) {
    curr = curr->next;
    i++;
  }
  if (!curr) {
    return Item();
  }
  return curr->item;
}
