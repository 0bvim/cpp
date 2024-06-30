#include <gtest/gtest.h>

TEST(SampleTest, AssertionTrue) { ASSERT_TRUE(true); }

int main(int ac, char **av) {
  ::testing::InitGoogleTest(&ac, av);
  return RUN_ALL_TESTS();
}
