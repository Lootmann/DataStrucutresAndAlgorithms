#pragma once

#include <vector>

class Graph {
private:
  int m_size;
  std::vector<std::vector<int>> graph;

public:
  Graph(int size);

  void add(int, int);
  void dfs(int start);
  void bfs(int start);
  int size() const;
};
