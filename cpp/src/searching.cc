#include "../include/searching.hpp"

template <typename T>
int Searching<T>::LinearSearch(std::vector<T> const &vec, T key) {
  int idx = -1;
  for (int i = 0; i < (int)vec.size(); ++i) {
    if (vec[i] == key) return i;
  }
  return idx;
}
