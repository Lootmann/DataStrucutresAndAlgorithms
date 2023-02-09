#pragma once

#include <iostream>
#include <vector>

// for simplicity use vector<T>
template <typename T>
class Searching {
public:
  static int LinearSearch(std::vector<T> const &, T);
  static int BinarySearch(std::vector<T> const &, T);
};

template class Searching<int>;
template class Searching<long>;
template class Searching<long long>;
template class Searching<double>;
template class Searching<float>;
template class Searching<char>;
