#include <gtest/gtest.h>
#include "matrix.cpp"
#include "../number/ff.cpp"

TEST(matrix, basic) {
  matrix<FF> a(2, 2,
      ffvec(7, {3, 2, 6, 0}) );

  EXPECT_EQ(matrix<FF>(2, 2, ffvec(7, {6, 4, 5, 0})), a + a);
  EXPECT_EQ(matrix<FF>(2, 2, ffvec(7, {0, 6, 4, 5})), a * a);

  auto b = a;
  REP(i, 5)
    b *= a;
  EXPECT_EQ(b, pow(a, 6));
}
