#pragma once

#include <iostream>
#include <vector>

using std::vector;

class Graph {
private:
  int m_size;
  vector<vector<int>> graph;

public:
  Graph(int size);

  void add(int, int);
  void dfs(int start);
  void bfs(int start);
  int size() const;
};

class GridGraph {
private:
  int m_size;
  vector<vector<bool>> graph;

  void traverse(int, int, vector<vector<int>>&, int);

public:
  GridGraph(int size);
  void Add(int, int);
  int ConnectedComponents();

  int Size() const;
};
