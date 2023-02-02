// include/queue.hpp
#pragma once
#include "./linked_list_node.hpp"

class Queue {
private:
  int m_size;
  LinkedListNode *head, *tail;

public:
  Queue();
  ~Queue();

  void enqueue(int);
  int dequeue();
  int front();
  int back();
  bool empty();
  int size() const;
};
