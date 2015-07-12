class Solution {
public:
    int climbStairs(int n) {
        if(!n) return 0;
        vector<int> vec(n);
        vec[0] = 1;
        vec[1] = 2;
        for(int i = 2; i<n; i++)
            vec[i] = vec[i-1] + vec[i-2];
        return vec[n-1];
    }
};

class Solution {
public:
    int climbStairs(int n) {
        if(!n) return 0;
        int f1 = 1;
        int f2 = 2;
        if(n==1) return f1;
        if(n==2) return f2;
        int i = 3;
        while(i<=n){
            int temp = f2;
            f2 += f1;
            f1 = temp;
            i++;
        }
        return f2;
    }
};
