#include <gtest/gtest.h>
#include "basic.cpp"

TEST(basic, factorize) {
  vi primes, orders;
  factorize(20, primes, orders);
  EXPECT_EQ(vi({2,5}), primes);
  EXPECT_EQ(vi({2,1}), orders);
}
