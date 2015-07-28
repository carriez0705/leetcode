class Solution {
public:
    int hammingWeight(uint32_t n) {
        int ham = 0;
        for(int i = 0; i<32; i++){
            if(n &(1<<i)) ham += 1;
        }
        return ham;
    }
};
