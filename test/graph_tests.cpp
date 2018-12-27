#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "graph.hpp"

namespace algorithms {
namespace tests {

TEST(graph,eventual_safe_nodes_test) {
  using testcase = ::std::pair<::std::vector<::std::vector<int>>,::std::vector<int>>;
  ::std::vector<testcase> testcases = {
    {{{1,2},{2,3},{5},{0},{5},{},{}},{2,4,5,6}}
  };
  for (auto &[v, r] : testcases) {
    ASSERT_THAT(graph::eventual_safe_nodes(v),::testing::Eq(r));
  }
}


} // tests
} // algorithms
