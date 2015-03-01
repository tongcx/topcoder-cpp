#include <gtest/gtest.h>
#include "matrix.cpp"
#include "../number/ff.cpp"

TEST(matrix, basic) {
  matrix<FF> a(2, 2,
      ffvec(7, {3, 2, 6, 0}) );

  EXPECT_EQ(matrix<FF>(2, 2, ffvec(7, {6, 4, 5, 0})), a + a);

  WATCH(a);
  WATCH(a * a);
}
