#pragma once

#include <iostream>
#include <vector>

// for simplicity use vector<T>
template <typename T>
class Sorting {
public:
  static void BubbleSort(std::vector<T> &);
  static void SelectionSort(std::vector<T> &);
};

template class Sorting<int>;
template class Sorting<long>;
template class Sorting<long long>;
template class Sorting<double>;
template class Sorting<float>;
template class Sorting<char>;
