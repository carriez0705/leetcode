class Solution {
    int sqrt_(int x){
        int left = 0, right = min(x/2, 46340);
        while(left<=right){
            int inter = (left+right)/2;
            int square = inter*inter;
            if(square == x)
                return inter;
            else if(square < x ){
                if(inter==46340 || (square + 2*inter + 1)>x)
                    return inter;
                else
                    left = inter+1;
            }
            else
                right = inter-1;
            
        }
        return 1;
    }
public:
    int mySqrt(int x) {
        if(x==0) return 0;
        if(x==1 ||x==2 || x==3) return 1;
        return sqrt_(x);
    }
};
