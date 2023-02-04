#include "../include/array.hpp"

Array::Array() : m_size(10), m_array(new int[10]) {
  for (int i = 0; i < m_size; ++i) {
    m_array[i] = 0;
  }
}

Array::Array(int size) : m_size(size) {
  assert(0 < size);
  m_array = new int[m_size];
}

Array::Array(int size, int fill) : m_size(size) {
  m_array = new int[size];
  for (int i = 0; i < size; ++i) {
    m_array[i] = fill;
  }
}

Array::~Array() {
  delete[] m_array;
}

int &Array::operator[](int idx) const {
  assert(0 <= idx && idx < m_size);
  return m_array[idx];
}

Array &Array::operator=(const Array &array) {
  // same array
  if (this == &array) return *this;

  if (m_size != array.m_size) {
    delete[] m_array;
    m_array = nullptr;

    m_size = array.size();
    m_array = new int[m_size];
  }

  for (int i = 0; i < size(); ++i) {
    m_array[i] = array[i];
  }

  return *this;
}

int Array::size() const {
  return m_size;
}
