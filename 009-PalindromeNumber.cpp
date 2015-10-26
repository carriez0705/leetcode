class Solution {
public:
    bool isPalindrome(int x) {
        long long reverse = 0;
        bool neg = true;
        if(x<0){
            neg = true;
            x = -x;
            return false;
        }
        int original = x;
        while(x){
            int b = x%10;
            x = x/10;
            reverse = reverse*10+b;
            if((!neg && reverse>INT_MAX) || (neg && reverse<INT_MIN))
                return false;
        }
        return (int)reverse==original;
    }
};
