class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t result = 0;
        for(int i = 0; i<16; i++){
            uint32_t bit = n&(1<<i);
            result |= (bit<<(31-2*i));
        }
        for(int i = 16; i<32; i++){
            uint32_t bit = n&(1<<i);
            result |=(bit>>(2*i-31));
        }
        return result;
    }
};
