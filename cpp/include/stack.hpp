// include/stack.hpp
#pragma once

#include <iostream>

#include "../include/linked_list_node.hpp"

class Stack {
private:
  int m_size;
  LinkedListNode *head;

public:
  Stack();
  ~Stack();

  void push(int);
  int pop();
  int top();
  bool empty();
  // NOTE: what is const?
  int size() const;
};

class MinStack {
private:
  int m_size;
  Stack m_current, m_min;

public:
  MinStack();
  ~MinStack();

  void push(int);
  int pop();
  int top();
  int min();
  bool empty();
  int size() const;
};
