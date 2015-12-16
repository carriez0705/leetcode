
class Solution {
    int findmin(vector<int> &ugly, vector<int> &pointer, vector<int> &primes){
        int p = 0;
        int minval = INT_MAX;
        for(int i = 0; i<pointer.size(); i++){
            int val = ugly[pointer[i]]*primes[i];
            if( val < minval){
                minval = val;
                p = i;
            }
        }
        int val = ugly[pointer[p]]*primes[p];
        pointer[p] += 1;
        return val;
    }
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        vector<int> ugly(1,1);
        int num = 1;
        int k = primes.size();
        vector<int> pointer(k, 0);
        while(--n){
            num = findmin(ugly, pointer, primes);
            while(num==ugly[ugly.size()-1])
                num = findmin(ugly, pointer, primes);
            ugly.push_back(num);
        }
        return  num;
    }
};
