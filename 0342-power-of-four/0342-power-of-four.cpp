class Solution {
 public:
  bool isPowerOfFour(unsigned n) {
    return n > 0 && popcount(n) == 1 && (n - 1) % 3 == 0;
  }
};