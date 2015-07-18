class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int> nset;
        while(nset.find(n)==nset.end()){
            nset.insert(n);
            int sum = 0;
            while(n/10){
                sum += (n%10)*(n%10);
                n /= 10;
            }
            sum += (n%10)*(n%10);
            if(sum==1) return true;
            
            n = sum;
        }
        return false;
    }
};
