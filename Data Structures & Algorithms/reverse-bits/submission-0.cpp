class Solution {
public:
    uint32_t reverseBits(uint32_t n) {

        uint32_t ans = 0;

        for (int i = 0; i < 32; i++) {

            ans <<= 1;          // make space

            ans |= (n & 1);     // copy last bit

            n >>= 1;            // remove last bit
        }

        return ans;
    }
};