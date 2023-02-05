#include "../include/queue_ring_buffer.hpp"

template <class T>
RingBufferQueue<T>::RingBufferQueue() : m_size(10), m_head(0), m_tail(0) {
  m_array = new T[m_size];
}

template <class T>
RingBufferQueue<T>::RingBufferQueue(int size)
    : m_size(size), m_head(0), m_tail(0) {
  m_array = new T[m_size];
}

template <class T>
RingBufferQueue<T>::~RingBufferQueue() {
  delete m_array;
}

template <class T>
void RingBufferQueue<T>::enqueue(T val) {
  if (is_full()) throw std::out_of_range("Queue is Full");
  m_array[m_tail] = val;
  m_tail = rot(m_tail);
}

template <class T>
T RingBufferQueue<T>::dequeue() {
  if (is_empty()) throw std::out_of_range("Queue is Empty");
  T val = m_array[m_head];
  m_head = rot(m_head);
  return val;
}

template <class T>
T RingBufferQueue<T>::front() {
  if (is_empty()) throw std::out_of_range("Queue is Empty");
  return m_array[m_head];
}

template <class T>
T RingBufferQueue<T>::back() {
  if (is_empty()) throw std::out_of_range("Queue is Empty");
  return m_array[m_tail - 1];
}

template <class T>
int RingBufferQueue<T>::rot(int idx) {
  return (idx + 1) % m_size;
}

template <class T>
bool RingBufferQueue<T>::is_empty() {
  // same position
  return m_head == m_tail;
}

template <class T>
bool RingBufferQueue<T>::is_full() {
  // the next pos after m_head is the same as m_tail
  return rot(m_tail) == m_head;
}

template <class T>
int RingBufferQueue<T>::size() const {
  return ((m_tail + m_size) - m_head) % m_size;
}
