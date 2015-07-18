class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int prev = INT_MIN, next = 0;
        for(int i = 0; i<nums.size(); i++){
            next = i<nums.size()-1?nums[i+1]:INT_MIN;
            if(nums[i]>=prev && nums[i]>=next) return i;
            prev = nums[i];
        }
        return -1;
    }
};
