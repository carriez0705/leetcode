class Solution {
public:
    int nthUglyNumber(int n) {
        set<long long> ugly;
        ugly.insert(1);
        while(--n){
            long long u = *ugly.begin();
            ugly.insert(u*2);
            ugly.insert(u*3);
            ugly.insert(u*5);
            ugly.erase(u);
        }
        return *ugly.begin();
    }
};
