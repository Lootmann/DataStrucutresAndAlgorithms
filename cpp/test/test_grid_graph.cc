#include <gtest/gtest.h>

#include <iostream>
#include <utility>
#include <vector>

#include "../include/graph.hpp"
using std::make_pair;
using std::pair;

#define mp make_pair

class GridGraphTest : public testing::Test {
protected:
  /*
   *   | 0 1 2 3 4
   * --+----------
   * 0 | 1 1 0 0 1
   * 1 | 1 0 0 0 0
   * 2 | 1 1 1 0 1
   * 3 | 0 0 0 0 1
   * 4 | 0 0 1 1 1
   * */
  GridGraph graph5{5};

  /*
   *   | 0 1 2 3 4 5
   * --+------------
   * 0 | 1 0 1 0 1 0
   * 1 | 0 1 0 1 0 1
   * 2 | 1 0 1 0 1 0
   * 3 | 0 1 0 1 0 1
   * 4 | 1 0 1 0 1 0
   * 5 | 0 1 0 1 0 1
   * */

  GridGraph graph6{6};

  void SetUp() override {
    // init graph5
    vector<pair<int, int>> vp{
        mp(0, 0), mp(0, 1), mp(0, 2), mp(0, 4), mp(1, 0), mp(2, 0), mp(2, 1),
        mp(2, 2), mp(2, 4), mp(3, 4), mp(4, 2), mp(4, 3), mp(4, 4),

    };

    for (auto key : vp) {
      graph5.Add(key.first, key.second);
    }

    // init graph6
    vector<pair<int, int>> vp1{
        mp(0, 0), mp(0, 2), mp(0, 4), mp(1, 1), mp(1, 3), mp(1, 5),
        mp(2, 0), mp(2, 2), mp(2, 4), mp(3, 1), mp(3, 3), mp(3, 5),
        mp(4, 0), mp(4, 2), mp(4, 4), mp(5, 1), mp(5, 3), mp(5, 5),
    };

    for (auto key : vp1) {
      graph6.Add(key.first, key.second);
    }
  }

  virtual void TearDown() override {}
};

TEST_F(GridGraphTest, ConnectedComponentsToGraph5) {
  int num = graph5.ConnectedComponents();
  EXPECT_EQ(num, 3);
}

TEST_F(GridGraphTest, ConnectedComponentsToGraph6) {
  int num = graph6.ConnectedComponents();
  EXPECT_EQ(num, 18);
}
