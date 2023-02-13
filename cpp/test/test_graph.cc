#include <gtest/gtest.h>

#include <iostream>
#include <utility>
#include <vector>

#include "../include/graph.hpp"
#define P std::pair<int, int>
#define mp std::make_pair

using std::vector;

class GraphTest : public testing::Test {
protected:
  Graph graph{9};
  vector<P> vec{
      mp(0, 1), mp(0, 2), mp(0, 4), mp(1, 3), mp(1, 8), mp(2, 5),
      mp(3, 7), mp(3, 8), mp(4, 8), mp(5, 6), mp(5, 8), mp(6, 7),
  };

  void SetUp() override {}
  virtual void TearDown() override {}
};

TEST_F(GraphTest, Dfs) {
  for (int i = 0; i < (int)vec.size(); ++i) {
    graph.add(vec[i].first, vec[i].second);
  }

  testing::internal::CaptureStdout();
  graph.dfs(0);
  std::string output = testing::internal::GetCapturedStdout();
  EXPECT_EQ("0 4 8 5 6 7 3 2 1 \n", output);
}

TEST_F(GraphTest, Bfs) {
  for (int i = 0; i < (int)vec.size(); ++i) {
    graph.add(vec[i].first, vec[i].second);
  }

  testing::internal::CaptureStdout();
  graph.bfs(0);
  std::string output = testing::internal::GetCapturedStdout();
  EXPECT_EQ("0 1 2 4 3 8 5 7 6 \n", output);
}
