class Solution {
public:
    int rob(vector<int>& nums) {
        if(!nums.size()) return 0;
        if(nums.size()==1) return nums[0];
        vector<vector<int> > vec(nums.size(), vector<int>(2,0));
        vec[0][0] = 0;
        vec[0][1] = nums[0];
        for(int i = 1; i<nums.size(); i++){
            vec[i][0] = max(vec[i-1][0], vec[i-1][1]);
            vec[i][1] = vec[i-1][0]+nums[i];
        }
        int r0 = vec[nums.size()-1][0];
        vec[0][0] = 0;
        vec[0][1] = 0;
        for(int i = 1; i<nums.size(); i++){
            vec[i][0] = max(vec[i-1][0], vec[i-1][1]);
            vec[i][1] = vec[i-1][0]+nums[i];
        }
        int r1 = vec[nums.size()-1][1];
        return max(r0,r1);
    }
};
