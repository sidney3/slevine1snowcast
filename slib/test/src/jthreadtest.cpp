#include "jthread.h"
#include <gtest/gtest.h>

TEST(JThreadTest, JThreadJoins) {
  std::atomic<bool> joined = false;

  {
    auto thr = [&joined](const std::atomic<bool> &joinFlag) {
      while (joinFlag)
        ;

      joined = true;
    };
    slib::jthread jt{thr};
  }

  EXPECT_EQ(joined.load(), true);
}