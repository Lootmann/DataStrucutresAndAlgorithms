#pragma once

#include <iostream>

#include "../include/array.hpp"

template <class T>
class Heap {
private:
  int n;
  Array<T> array;

  int left(int);
  int right(int);
  int parent(int);

public:
  Heap();

  bool add(T);
  void bubbleUp(int);
  T remove();
  void tickleDown(int);
  int size() const;
};

template class Heap<int>;
template class Heap<long>;
template class Heap<long long>;
