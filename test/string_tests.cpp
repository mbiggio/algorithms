#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "string.hpp"
#include <vector>

namespace algorithms {
namespace tests {

TEST(string,count_substrings_test) {
  using testcase = ::std::pair<::std::string, int>;
  ::std::vector<testcase> testcases = {
    {"",0},
    {"a",1},
    {"ab",2},
    {"aa",3},
    {"abc",3},
    {"aac",4},
    {"aba",4},
    {"abb",4},
    {"aaa",6},
    {"aaaa",10}
  };
  for (auto &[s, r] : testcases) {
    ASSERT_EQ(r, string::count_substrings(s));
  }
}

TEST(string,find_lus_length_test) {
  using testcase = ::std::pair<::std::vector<::std::string>, int>;
  ::std::vector<testcase> testcases = {
    {{"aba","cdc","eae"},3},
    {{"aba","aba","aba"},-1},
    {{"aba","aa","bc"},3}
  };
  for (auto &[v, r] : testcases) {
    ASSERT_EQ(r, string::find_lus_length(v));
  }
}


} // tests
} // algorithms