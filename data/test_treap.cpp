#include <gtest/gtest.h>
#include "treap.cpp"

TEST(data, treap) {
  treap<int> t;
  REP(i, 10)
    t.insert(i);

  EXPECT_EQ(5, t.kth(5));
  EXPECT_EQ(10, t.size());

  t.insert(5);
  EXPECT_EQ(5, t.position(5));
  EXPECT_EQ(7, t.position(6));
  EXPECT_EQ(11, t.size());

  EXPECT_TRUE(t.contain(6));
  EXPECT_TRUE(t.contain(2));
  EXPECT_FALSE(t.contain(-1));
  EXPECT_FALSE(t.contain(20));
}
