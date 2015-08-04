class Solution {
public:
    int findHighest(int n){
        while(n&(n-1))
            n = n&(n-1);
        int count = 0;
        while(n>>1){
            n = n>>1;
            count += 1;
        }
       return count; 
    }
    int rangeBitwiseAnd(int m, int n) {
        if(m==n) return m;
        if(m==0||n==0) return 0;
        int c1 = findHighest(m);
        int c2 = findHighest(n);
        if(c1!=c2) return 0;
        else{
            int mask = 1<<c1;
            int m1 = m&mask;
            int n1 = n&mask;
            while(m1==n1){
                mask = mask|(1<<c1);
                c1--;
                m1 = m&(1<<c1);
                n1 = n&(1<<c1);
            }
            return m&mask;
        }
    }
};
