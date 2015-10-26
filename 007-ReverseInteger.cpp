class Solution {
   
public:
    int reverse(int x) {
        if(!x) return x;
        if(x==INT_MIN) return 0;
        bool neg = false;
        if(x<0){
           x = -x;
           neg = true;
        } 
        int reverse = 0;
        int num = 0;
        int a1 = INT_MAX/10;
        while(x>0){
            int b = x%10;
            x = x/10;
            num += 1;
            if(num == 10 && reverse>a1){
                return 0;
            }
            reverse = reverse*10+b;
        }
        return neg?-reverse:reverse;
    }
};
