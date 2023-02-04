// include/deq.hpp
#pragma once

#include <iostream>

#include "./doubly_linked_list_node.hpp"

class Deq {
private:
  int m_size;
  DoublyLinkedListNode *m_head;

public:
  Deq();
  ~Deq();

  // Queue
  void push_front(int);
  int pop_front();
  int front();

  // Stack
  void push_back(int);
  int pop_back();
  int back();

  // utils
  bool empty() const;
  int size() const;
};
