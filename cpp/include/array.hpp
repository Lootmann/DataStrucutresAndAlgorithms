// include/array.hpp
#pragma once

#include <algorithm>
#include <cassert>
#include <string>

template <class T>
class Array {
private:
  int m_size;
  T* m_array;

public:
  Array();
  Array(int size);
  Array(int size, int fill);
  ~Array();

  T& operator[](int idx);
  Array<T>& operator=(Array<T>&);
  int size() const;
};

template class Array<int>;
template class Array<long int>;
template class Array<long long int>;
template class Array<char>;
template class Array<std::string>;
