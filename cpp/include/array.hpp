// include/array.hpp
#pragma once

#include <algorithm>
#include <cassert>

class Array {
private:
  int m_size;
  int* m_array;

public:
  Array();
  Array(int size);
  Array(int size, int fill);
  ~Array();

  int& operator[](int idx) const;
  Array& operator=(const Array& array);
  int size() const;
};
