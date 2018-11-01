#include <gtest/gtest.h>
#include <bitwise.hpp>
#include <vector>

namespace algorithms {
namespace tests {

TEST(bitwise,count_bits) {
  using testcase = std::pair<short, unsigned>;
  const std::vector<testcase> testcases = { {0,0},{1,1},{1,1 << 1},{2,1+(1<<3)} };
  for (const auto &[output, input] : testcases) {
    ASSERT_EQ(output, bitwise::count_bits(input));
  }
}

} // tests
} // algorithms
