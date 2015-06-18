class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int localmax = 0;
        int maxs = INT_MIN;
        for(int i = 0;i<nums.size(); i++){
            localmax = max(localmax+nums[i], nums[i]);
            maxs = max(maxs,localmax);
        }
        return maxs;
    }
};
