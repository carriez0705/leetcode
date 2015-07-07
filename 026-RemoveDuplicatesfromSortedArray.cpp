class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int len = 0;
        int i = -1, j = 0;
        while(j<nums.size()){
            while(j<nums.size()-1 && nums[j+1]==nums[j])
                j++;
            nums[++i] = nums[j++];
        }
        return i+1;
    }
};
