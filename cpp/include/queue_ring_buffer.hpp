// include/queue_ring_buffer.hpp
#pragma once
#include <iostream>

#include "../include/queue_ring_buffer.hpp"

template <class T>
class RingBufferQueue {
private:
  int m_size;
  int m_head, m_tail;  // point to head, tail Node
  T *m_array;

public:
  RingBufferQueue();
  RingBufferQueue(int);
  ~RingBufferQueue();

  void enqueue(T);
  T dequeue();
  T front();
  T back();
  int rot(int);
  bool is_empty();
  bool is_full();
  int size() const;
};

// explicit instantiations
template class RingBufferQueue<int>;
template class RingBufferQueue<long>;
template class RingBufferQueue<long long int>;
template class RingBufferQueue<double>;
template class RingBufferQueue<float>;
template class RingBufferQueue<char>;
