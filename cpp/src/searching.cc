#include "../include/searching.hpp"

template <typename T>
int Searching<T>::LinearSearch(std::vector<T> const &vec, T key) {
  int idx = -1;
  for (int i = 0; i < (int)vec.size(); ++i) {
    if (vec[i] == key) return i;
  }
  return idx;
}

template <typename T>
int Searching<T>::BinarySearch(std::vector<T> const &vec, T key) {
  // NOTE: this function needs sorted vec
  int low = 0;
  int high = (int)vec.size() - 1;

  while (low <= high) {
    int mid = low + (high - low) / 2;
    if (vec[mid] == key)
      return mid;
    else if (vec[mid] < key)
      low = mid + 1;
    else
      high = mid - 1;
  }

  return -1;
}
