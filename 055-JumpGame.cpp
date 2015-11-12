class Solution {
public:
    bool canJump(vector<int>& nums) {
        int farest = 0;
        for(int i = 0; i<nums.size() && i<=farest; i++){
            int jump = i+nums[i];
            if(jump>=nums.size()-1) return true;
            farest = max(farest, jump);
        }
        return false;
    }
};
