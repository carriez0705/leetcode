class Solution {
public:
    int maxProduct(vector<int>& nums) {
        if(!nums.size()) return 0;
        int maxp= INT_MIN;
        int localmax = 1;
        int localmin = 1;
        
        for(int i = 0; i<nums.size(); i++){
            if(!nums[i]){
                maxp = max(maxp,nums[i]);
                
                localmax = 1;
                localmin = 1;
            }
            else{
                int lmin = min(localmin*nums[i], localmax*nums[i]);
                lmin = min(lmin,nums[i]);
                localmax = max(localmax*nums[i], localmin*nums[i]);
                localmax = max(localmax,nums[i]);
                maxp = max(maxp,localmax);
                localmin = lmin;
            }
        }
        return maxp;
    }
};
