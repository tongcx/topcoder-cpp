#include <gtest/gtest.h>
#include "number/test_basic.cpp"
#include "number/test_ff.cpp"
#include "linalg/test_matrix.cpp"
#include "data/test_treap.cpp"

int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
