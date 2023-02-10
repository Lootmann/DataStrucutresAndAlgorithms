#include "../include/array.hpp"

template <class T>
Array<T>::Array() : Array(10, 0) {}

template <class T>
Array<T>::Array(int size) : Array(size, 0) {}

template <class T>
Array<T>::Array(int size, int fill) : m_size(size) {
  m_array = new T[size];
  for (int i = 0; i < size; ++i) {
    m_array[i] = fill;
  }
}

template <class T>
Array<T>::~Array() {
  delete[] m_array;
}

template <class T>
T &Array<T>::operator[](int idx) {
  assert(0 <= idx && idx < m_size);
  return m_array[idx];
}

template <class T>
Array<T> &Array<T>::operator=(Array<T> &array) {
  // same array
  if (this == &array) return *this;

  if (m_size != array.m_size) {
    delete[] m_array;
    m_array = nullptr;

    m_size = array.size();
    m_array = new T[m_size];
  }

  for (int i = 0; i < size(); ++i) {
    m_array[i] = array[i];
  }

  return *this;
}

template <class T>
int Array<T>::size() const {
  return m_size;
}
