#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "array.hpp"
#include <vector>

namespace algorithms {
namespace tests {

TEST(array,multiply_test) {
  using testcase = ::std::tuple<::std::vector<int>, ::std::vector<int>, ::std::vector<int>>;
  ::std::vector<testcase> testcases = { 
    {{},{1,2,3},{0}},
    {{0},{1,2,3},{0}},
    {{1,2,3},{},{0}},
    {{1,2,3},{0},{0}},
    {{},{},{0}},
    {{},{0},{0}},
    {{0},{},{0}},
    {{0},{0},{0}},
    {{1,2,3},{4,5,6},{5,6,0,8,8}},
    {{-1,2,3},{4,5,6},{-5,6,0,8,8}},
    {{1,2,3},{-4,5,6},{-5,6,0,8,8}},
    {{0},{-0},{0}},
    {{-0},{0},{0}}
  };
  for (auto &[a, b, r] : testcases) {
    ASSERT_THAT(r, ::testing::Eq(array::multiply(a,b)));
  }
}

TEST(array,can_reach_end_test) {
  using testcase = ::std::tuple<::std::vector<int>, int>;
  ::std::vector<testcase> testcases = { 
    {{0},0},
    {{0,0},-1},
    {{3,3,1,0,2,0,1},3},
    {{3,2,0,0,2,0,1},-1}
  };
  for (auto &[a, r] : testcases) {
    ASSERT_EQ(r, array::can_reach_end(a));
  }
}

TEST(array,delete_dupes_test) {
  using testcase = ::std::pair<::std::vector<int>, int>;
  ::std::vector<testcase> testcases = { 
    {{},0},
    {{1},1},
    {{1,2},2},
    {{1,2,3},3},
    {{1,1,2,3},3},
    {{1,2,2,3},3},
    {{1,2,3,3},3},
    {{1,1,2,2,3},3},
    {{1,1,2,3,3},3},
    {{1,2,2,3,3},3},
    {{1,1,1,1,1},1}
  };
  for (auto &[a, r] : testcases) {
    ASSERT_EQ(r, array::delete_dupes(&a));
    ASSERT_EQ(r,a.size());
    ::std::vector<int> v;
    for (int i=1; i<=r; ++i) v.push_back(i);
    ASSERT_THAT(v,::testing::Eq(a));
  }
}

TEST(array,buy_and_sell_stock_once_test) {
  using testcase = ::std::pair<::std::vector<double>, double>;
  ::std::vector<testcase> testcases = {
    {{},0.0},
    {{0.0},0.0},
    {{10.0},0.0},
    {{20.0,10.0},0.0},
    {{10.0,20.0},10.0},
    {{310.0,315.0,275.0,295.0,260.0,270.0,290.0,230.0,255.0,250.0},30.0}
  };
  for (auto &[a, r] : testcases) {
    ASSERT_EQ(r, array::buy_and_sell_stock_once(a));
  }
}

TEST(array,buy_and_sell_stock_twice_test) {
  using testcase = ::std::pair<::std::vector<double>, double>;
  ::std::vector<testcase> testcases = {
    {{},0.0},
    {{0.0},0.0},
    {{10.0},0.0},
    {{20.0,10.0},0.0},
    {{12.0,11.0,13.0,9.0,12.0,8.0,14.0,13.0,15.0},10.0}
  };
  for (auto &[a, r] : testcases) {
    ASSERT_EQ(r, array::buy_and_sell_stock_twice(a));
  }
}

TEST(array,beautiful_arrangement_ii_test) {
  using testcase = ::std::tuple<int,int,::std::vector<int>>;
  ::std::vector<testcase> testcases = {
    {2,1,{1,2}},
    {3,1,{1,2,3}},
    {3,2,{1,3,2}},
    {4,1,{1,2,3,4}},
    {4,2,{1,2,4,3}},
    {4,3,{1,4,2,3}},
    {5,1,{1,2,3,4,5}},
    {5,2,{1,2,3,5,4}},
    {5,3,{1,2,5,3,4}},
    {5,4,{1,5,2,4,3}}
  };
  for (auto &[n, k, r] : testcases) {
    ASSERT_THAT(r, ::testing::Eq(array::beautiful_arrangement_ii(n,k)));
  }
}

TEST(array,generate_primes_test) {
  using testcase = ::std::tuple<int,::std::vector<int>>;
  ::std::vector<testcase> testcases = {
    {0,{}},
    {1,{}},
    {2,{2}},
    {3,{2,3}},
    {4,{2,3}},
    {5,{2,3,5}},
    {6,{2,3,5}},
    {7,{2,3,5,7}},
    {8,{2,3,5,7}},
    {9,{2,3,5,7}},
    {10,{2,3,5,7}},
    {11,{2,3,5,7,11}},
    {12,{2,3,5,7,11}},
    {13,{2,3,5,7,11,13}},
    {14,{2,3,5,7,11,13}},
    {15,{2,3,5,7,11,13}},
    {16,{2,3,5,7,11,13}},
    {17,{2,3,5,7,11,13,17}},
    {18,{2,3,5,7,11,13,17}}
  };
  for (auto &[n, r] : testcases) {
    ASSERT_THAT(r, ::testing::Eq(array::generate_primes(n)));
  }
}

TEST(array,apply_permutation_test) {
  using testcase = ::std::tuple<::std::vector<int>,::std::vector<int>,::std::vector<int>>;
  ::std::vector<testcase> testcases = {
    {{},{},{}},
    {{0},{10},{10}},
    {{0,1},{11,10},{11,10}},
    {{1,0},{11,10},{10,11}},
    {{0,1,2},{12,11,10},{12,11,10}},
    {{0,2,1},{12,11,10},{12,10,11}},
    {{1,0,2},{12,11,10},{11,12,10}},
    {{1,2,0},{12,11,10},{10,12,11}},
    {{2,0,1},{12,11,10},{11,10,12}},
    {{2,1,0},{12,11,10},{10,11,12}},
    {{0,1,2,3},{13,12,11,10},{13,12,11,10}},
    {{2,0,1,3},{13,12,11,10},{12,11,13,10}}
  };
  for (auto &[p, v, r] : testcases) {
    ASSERT_NO_THROW(array::apply_permutation(p,&v));
    ASSERT_THAT(r, ::testing::Eq(v));
  }
}

} // tests
} // algorithms
