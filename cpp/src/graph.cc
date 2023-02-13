#include "../include/graph.hpp"

#include <algorithm>
#include <iostream>
#include <queue>
#include <stack>
#include <vector>

Graph::Graph(int size) : m_size(size) {
  graph.resize(m_size, std::vector<int>(0));
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
  std::vector<bool> visited(m_size, false);

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
