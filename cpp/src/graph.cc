#include "../include/graph.hpp"

#include <algorithm>
#include <iostream>
#include <queue>
#include <stack>
#include <vector>

Graph::Graph(int size) : m_size(size) {
  graph.resize(m_size, vector<int>(0));
}

void Graph::add(int n, int m) {
  graph[n].emplace_back(m);
  graph[m].emplace_back(n);
}

int Graph::size() const {
  return m_size;
}

void Graph::dfs(int start) {
  std::vector<bool> visited(m_size, false);

  std::stack<int> st;
  st.push(start);
  visited[start] = true;

  while (st.size() > 0) {
    int v = st.top();
    st.pop();
    std::cout << v << ' ';

    for (auto &nv : graph[v]) {
      if (visited[nv]) continue;
      st.push(nv);
      visited[nv] = true;
    }
  }

  std::cout << '\n';
}

void Graph::bfs(int start) {
  vector<bool> visited(m_size, false);

  std::queue<int> q;
  q.push(start);
  visited[start] = true;

  while (q.size() > 0) {
    int v = q.front();
    q.pop();
    std::cout << v << ' ';

    for (auto &nv : graph[v]) {
      if (visited[nv]) continue;
      q.push(nv);
      visited[nv] = true;
    }
  }

  std::cout << '\n';
}

GridGraph::GridGraph(int size) : m_size(size) {
  graph.resize(m_size, vector<bool>(m_size, false));
}

void GridGraph::Add(int y, int x) {
  graph[y][x] = true;
}

void GridGraph::traverse(int y, int x, vector<vector<int>> &seen, int id) {
  seen[y][x] = id;

  // 4 direction: up, down, left, right
  vector<int> dy{-1, 1, 0, 0}, dx{0, 0, -1, 1};

  for (int i = 0; i < 4; ++i) {
    int next_y = y + dy[i];
    int next_x = x + dx[i];

    if (0 <= next_y && next_y < m_size && 0 <= next_x && next_x < m_size) {
      if (graph[next_y][next_x] == true && seen[next_y][next_x] == -1) {
        seen[next_y][next_x] = id;
        traverse(next_y, next_x, seen, id);
      }
    }
  }
}

int GridGraph::ConnectedComponents() {
  vector<vector<int>> seen(m_size, vector<int>(m_size, -1));
  int num{0};

  for (int y = 0; y < m_size; ++y) {
    for (int x = 0; x < m_size; ++x) {
      // when the cell is true and unseen, start traverse
      if (graph[y][x] == true && seen[y][x] == -1) {
        traverse(y, x, seen, num++);
      }
    }
  }

  for (int y = 0; y < m_size; ++y) {
    for (int x = 0; x < m_size; ++x) {
      if (seen[y][x] == -1)
        printf("  x");
      else
        printf("%3d", seen[y][x]);
    }
    printf("\n");
  }

  return num;
}

int GridGraph::Size() const {
  return m_size;
}
