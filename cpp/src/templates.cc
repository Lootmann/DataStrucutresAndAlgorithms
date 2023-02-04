#include "../include/templates.hpp"

template <class T>
Foo<T>::Foo() : size_(0) {}

template <class T>
Foo<T>::~Foo() {}

template <class T>
T Foo<T>::add(T a, T b) {
  return a + b;
}

template <class T>
int Foo<T>::size() const {
  return size_;
}
