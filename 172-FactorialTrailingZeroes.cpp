class Solution {
public:
    int trailingZeroes(int n) {
        int i = 1;
        int ret = 0;
        while(n>=pow(5,i)){
            ret += n/pow(5,i);
            i++;
        }
        return ret;
    }
};
