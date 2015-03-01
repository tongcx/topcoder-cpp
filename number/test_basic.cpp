#include <gtest/gtest.h>
#include "basic.cpp"

TEST(basic, factorize) {
  vi primes, orders;
  factorize(20, primes, orders);
  EXPECT_EQ(vi({2,5}), primes);
  EXPECT_EQ(vi({2,1}), orders);
}

TEST(basic, eratosthenes) {
  EXPECT_EQ(vi({2,3,5,7,11,13,17,19}), eratosthenes(20));
}

TEST(basic, bezout) {
  int x, y;

  bezout(3, 4, x, y);
  EXPECT_EQ(1, 3*x + 4*y);

  bezout(6, 8, x, y);
  EXPECT_EQ(2, 6*x + 8*y);
}
