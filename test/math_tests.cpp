#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "math.hpp"

namespace algorithms {
namespace tests {

TEST(math,add_without_plus_test) {
  using testcase = ::std::tuple<int,int,int>;
  ::std::vector<testcase> testcases = {
    {1,1,2},
    {7,5,12},
    {7,-5,2},
    {-7,-5,-12}
  };
  for (auto &[a, b, r] : testcases) {
    ASSERT_EQ(r, math::add_without_plus(a,b));
  }
}

TEST(math,number_of_twos_test) {
  using testcase = ::std::pair<int,int>;
  ::std::vector<testcase> testcases = {
    //TODO
  };
  for (auto &[n, r] : testcases) {
    ASSERT_EQ(r, math::number_of_twos(n));
  }
}



} // tests
} // algorithms
