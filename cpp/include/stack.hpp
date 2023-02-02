// include/stack.hpp
#pragma once

#include <iostream>

#include "../include/linked_list_node.hpp"

class Stack {
private:
  int m_size;
  LinkedListNode* dummy;

public:
  Stack();

  void push(int);
  // TODO: return LinkedListNode or value?
  LinkedListNode* pop();
  // TODO: return Node or value?
  int top();
  bool empty();
  // NOTE: what is const?
  int size() const;
};
