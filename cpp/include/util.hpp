#include <algorithm>
#include <iostream>
#include <iterator>
#include <numeric>
#include <random>
#include <vector>

template <typename T>
std::vector<int> GenerateVector(std::size_t size = 20) {
  std::vector<int> v(size);
  std::iota(v.begin(), v.end(), 0);

  std::random_device seed_gen;
  std::mt19937 engine(seed_gen());
  std::shuffle(v.begin(), v.end(), engine);

  return v;
}
