class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        if(!digits.size()) return vector<int>(1,1);
        int carrie = 1;
        int n = digits.size();
        vector<int> ans(n, 0);
        int i = n-1;
        while(carrie){
            if(i<0){
                ans.insert(ans.begin(), 1);
                carrie = 0;
            }
            else{
                int d = digits[i]+carrie;
                carrie = 0;
                if(d>9){
                d -= 10;
                carrie = 1;
                }
                ans[i] = d;
                i--;
            }
        }
        while(i>=0){
            ans[i] = digits[i];
            i--;
        }
        return ans;
    }
};
