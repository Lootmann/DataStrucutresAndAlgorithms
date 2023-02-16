#include "../include/heap.hpp"

template <class T>
Heap<T>::Heap() : n(0), array{0} {}

template <class T>
int Heap<T>::left(int i) {
  return 2 * i + 1;
}

template <class T>
int Heap<T>::right(int i) {
  return 2 * i + 2;
}

template <class T>
int Heap<T>::parent(int i) {
  return (i - 1) / 2;
}

template <class T>
bool Heap<T>::add(T val) {
  if (n + 1 > array.size()) array.resize();
  array[n++] = val;
  bubbleUp(n - 1);
  return true;
}

template <class T>
void Heap<T>::bubbleUp(int idx) {
  int p = parent(idx);
  while (idx > 0 && array[idx] < array[p]) {
    T tmp = array[idx];
    array[idx] = array[p];
    array[p] = tmp;
    idx = p;
    p = parent(idx);
  }
}

template <class T>
T Heap<T>::remove() {
  T x = array[0];
  array[0] = array[--n];

  tickleDown(0);
  if (3 * n < array.size()) array.resize();
  return x;
}

template <class T>
void Heap<T>::tickleDown(int idx) {
  do {
    int j = -1;
    int r = right(idx);

    if (r < n && array[r] < array[idx]) {
      int l = left(idx);
      if (array[l] < array[r]) {
        j = l;
      } else {
        j = r;
      }
    } else {
      int l = left(idx);
      if (l < n && array[l] < array[idx]) {
        j = l;
      }
    }

    if (j >= 0) {
      int tmp = array[idx];
      array[idx] = array[j];
      array[j] = tmp;
    }
    idx = j;
  } while (idx >= 0);
}

template <class T>
int Heap<T>::size() const {
  return n;
}
