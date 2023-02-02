#include "../include/queue.hpp"

Queue::Queue() : head{nullptr}, tail{nullptr} {}

void Queue::enqueue(int val) {
  LinkedListNode* new_node = new LinkedListNode(val);

  m_size++;
  if (empty()) {
    head = tail = new_node;
    return;
  }

  tail->m_next = new_node;
  tail = new_node;
}

LinkedListNode* Queue::dequeue() {
  if (empty()) throw std::out_of_range("Queue is Empty");

  m_size--;
  LinkedListNode* f = head;
  head = head->m_next;

  if (empty()) tail = nullptr;
  return f;
}

int Queue::front() {
  if (empty()) throw std::out_of_range("Queue is Empty");
  return head->m_val;
}

int Queue::back() {
  if (empty()) throw std::out_of_range("Queue is Empty");
  return tail->m_val;
}

bool Queue::empty() {
  return head == nullptr || tail == nullptr;
}

int Queue::size() const {
  return m_size;
}
