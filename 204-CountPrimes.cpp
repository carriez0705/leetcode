class Solution {
public:
    int countPrimes(int n) {
        int count = 0;
        vector<char> pvec(n,0);
        int end = sqrt(INT_MAX);
        for(int i = 2; i<n; i++){
            if(!pvec[i]) count++;
            if(i>end) continue;
            int j = i*i;
            while(j<n){
                pvec[j]=1;
                j += i;
            }
        }
        return count;
    }
};
