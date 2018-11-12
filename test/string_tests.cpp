#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "string.hpp"
#include <vector>

namespace algorithms {
namespace tests {

TEST(string,is_palyndrome) {
  using testcase = ::std::pair<::std::string, bool>;
  ::std::vector<testcase> testcases = {
    {"",true},
    {"a",true},
    {"ab",false},
    {"aa",true},
    {"abc",false},
    {"aac",false},
    {"aba",true},
    {"abb",false},
    {"aaa",true}
  };
  for (auto &[s, r] : testcases) {
    ASSERT_EQ(r, string::is_palyndrome(s));
  }
}

TEST(string,string_to_int) {
  using testcase = ::std::pair<::std::string, int>;
  ::std::vector<testcase> testcases = {
    {"",0},
    {"-",0},
    {"0",0},
    {"00",0},
    {"000",0},
    {"1",1},
    {"2",2},
    {"12345",12345},
    {"-1",-1},
    {"-12345",-12345}
  };
  for (auto &[s, r] : testcases) {
    ASSERT_EQ(r, string::string_to_int(s));
  }
}

TEST(string,int_to_string) {
  using testcase = ::std::pair<int,::std::string>;
  ::std::vector<testcase> testcases = {
    {0,"0"},
    {-0,"0"},
    {1,"1"},
    {2,"2"},
    {12345,"12345"},
    {-1,"-1"},
    {-12345,"-12345"}
  };
  for (auto &[s, r] : testcases) {
    ASSERT_EQ(r, string::int_to_string(s));
  }
}

TEST(string,reverse_words) {
  using testcase = ::std::pair<::std::string,::std::string>;
  ::std::vector<testcase> testcases = {
    {"",""},
    {"alice likes bob","bob likes alice"},
    {"ciao","ciao"}
  };
  for (auto &[s,r]: testcases) {
    ASSERT_NO_THROW(string::reverse_words(&s));
    ASSERT_EQ(r,s);
  }
}

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

TEST(string,look_and_say_test) {
  using testcase = ::std::pair<int, ::std::string>;
  ::std::vector<testcase> testcases = {
    {1,"1"},
    {2,"11"},
    {3,"21"},
    {4,"1211"},
    {5,"111221"},
    {6,"312211"},
    {7,"13112221"},
    {8,"1113213211"}
  };
  for (auto &[i, r] : testcases) {
    ASSERT_EQ(r, string::look_and_say(i));
  }
}

TEST(string,roman_to_integer_test) {
  using testcase = ::std::pair<::std::string, int>;
  ::std::vector<testcase> testcases = {
    {"XXXXXIIIIIIIII",59},
    {"LVIIII",59},
    {"LIX",59}
  };
  for (auto &[i, r] : testcases) {
    ASSERT_EQ(r, string::roman_to_integer(i));
  }
}

TEST(string,search_test) {
  using testcase = ::std::tuple<::std::string, ::std::string, int>;
  ::std::vector<testcase> testcases = {
    {"GACGCCA","CGC",2},
    {"GACGCCA","CCC",-1}
  };
  for (auto &[s1, s2, r] : testcases) {
    ASSERT_EQ(r, string::search(s1,s2));
  }
}


} // tests
} // algorithms
