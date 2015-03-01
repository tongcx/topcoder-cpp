#include <gtest/gtest.h>
#include <unordered_set>
#include "ff.cpp"

TEST(FF, inv) {
  EXPECT_EQ( FF(11, 4), inv(FF(11, 3)) );
  EXPECT_EQ( FF(11, 2), inv(FF(11, 6)) );
  EXPECT_EQ( FF(11, 7), inv(FF(11, 8)) );
  EXPECT_EQ( FF(11, 8), inv(FF(11, 7)) );
}

TEST(FF, find_generator) {
  int p = 43;

  FF g = find_generator(p);
  FF h(p, 1);

  unordered_set<FF> s;

  REP(i, p - 1) {
    s.insert(h);
    h *= g;
  }

  EXPECT_EQ(p - 1, SZ(s));
}
