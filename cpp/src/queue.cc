#include "../include/queue.hpp"

Queue::Queue() : m_size{0}, head{nullptr}, tail{nullptr} {}

Queue::~Queue() {
  while (!empty()) {
    LinkedListNode* tmp = head;
    head = head->m_next;
    delete tmp;
  }
}

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

int Queue::dequeue() {
  if (empty()) throw std::out_of_range("Queue is Empty");

  m_size--;
  LinkedListNode* tmp = head;
  int val = tmp->m_val;
  head = head->m_next;
  delete tmp;

  if (empty()) tail = nullptr;
  return val;
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
