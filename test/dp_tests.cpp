#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "dp.hpp"

namespace algorithms {
namespace tests {

TEST(array,egg_drop_test) {
  using testcase = ::std::pair<int,int>;
  ::std::vector<testcase> testcases = {
    {100,14}
  };
  for (auto &[i, r] : testcases) {
    ASSERT_EQ(r,dp::egg_drop(i));
  }
}

} // tests
} // algorithms
