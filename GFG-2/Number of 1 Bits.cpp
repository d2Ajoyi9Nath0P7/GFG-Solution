class Solution {
  public:
    int setBits(int N) {
        bitset<32>b(N);
        return b.count();
    }
};