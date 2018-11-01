#include "bitwise.hpp"
#include <stdexcept>
#include <tuple>

namespace algorithms { 
namespace bitwise {

/************** count_bits ****************/
short count_bits(unsigned x) {
  short count = 0;
  while (x) {
    ++count;
    x &= x-1; // drop last bit
  }
  return count;
}

/************** parity ****************/
short parity(unsigned x) {
  static const int kBiteSize = 8;
  int shift = sizeof(x)*kBiteSize/2;
  while (shift) {
    x ^= x >> shift;
    shift >>= 1;
  }
  return x&1;
}

/************** swap_bits ****************/
unsigned swap_bits(unsigned x, int i, int j) {
  if (((x >> i) ^ (x >> j)) & 1) {
    x ^= (1 << i | 1 << j);
  }
  return x;
}

/************** reverse_bits ****************/
unsigned reverse_bits(unsigned x) {
  for (int i=0; i<8*sizeof(unsigned)/2; ++i) {
    x = swap_bits(x,i,8*sizeof(unsigned)-1-i);
  }
  return x;
}

/************** closest ****************/
unsigned closest(unsigned x) {
  for (int i=0; i<8*sizeof(unsigned)-1; ++i) {
    if (((x >> i) ^ (x >> i+1)) & 0x1) {
      return x ^ ((1 << i) | (1 << (i+1)));
    }
  }
  return x==0?x+3:x-3;
}

/************** multiply ****************/
unsigned multiply(unsigned a, unsigned b) {
  if (b==0) return 0;
  auto c = (multiply(a,b>>1) << 1);
  return b%2?c+a:c;
}

/************** divide ****************/
unsigned divide_nozero(unsigned a, unsigned b) {
  if (a < b) return 0;
  int cnt = 1;
  unsigned long long cur = b;
  while (static_cast<unsigned long long>(a) >= (cur << 1)) {
    cur <<= 1;
    cnt <<= 1;
  }
  return cnt + divide_nozero(a-cur,b);
}

unsigned divide(unsigned a, unsigned b) {
  if (b == 0) throw ::std::runtime_error("divide by zero");
  return divide_nozero(a, b);
}

/************** reverse_digits ****************/
::std::tuple<unsigned,unsigned> reverse_digits_helper(unsigned x) {
  if (x<10) return {10,x};
  unsigned msd = x%10;
  auto p = reverse_digits_helper(x/10);
  return {::std::get<0>(p)*10, ::std::get<0>(p)*msd + ::std::get<1>(p)};
}

unsigned reverse_digits(unsigned x) {
  if (x==0) return 0;
  return ::std::get<1>(reverse_digits_helper(x));
}

/************** power ****************/
double power_helper(double x, int m) {
  if (m == 0) return 1.0;
  double half = power_helper(x,m/2);
  return m%2?half*half*x:half*half;
}

double power(double x, int m) {
  if (x < 0.0) throw ::std::runtime_error("trying to exponentiate a negative number");
  if (x == 0.0) return 0.0;
  if (m < 0) {
    m = -m;
    x = 1.0/x;
  }
  return power_helper(x,m);
}

/************** is_palyndrome ****************/
bool is_palyndrome(unsigned x) {
  return x == reverse_digits(x);
}


} // bitwise
} // algorithms
