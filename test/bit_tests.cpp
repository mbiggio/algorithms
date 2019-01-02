#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "bit.hpp"

namespace algorithms {
namespace tests {

TEST(bit,count_smaller_test) {
  using testcase = ::std::pair<::std::vector<int>, ::std::vector<int>>;
  ::std::vector<testcase> testcases = {
    {{5,2,6,1},{2,1,1,0}}
  };
  for (auto &[i, r] : testcases) {
    ASSERT_THAT(bit::count_smaller(i), ::testing::Eq(r));
  }
}

TEST(bit,count_range_sum_test) {
  using testcase = ::std::tuple<::std::vector<int>,int,int,int>;
  ::std::vector<testcase> testcases = {
    {{-2,5,-1},-2,2,3}
  };
  for (auto &[v, l, u, r] : testcases) {
    ASSERT_THAT(bit::count_range_sum(v,l,u), ::testing::Eq(r));
  }
}

} // tests
} // algorithms
