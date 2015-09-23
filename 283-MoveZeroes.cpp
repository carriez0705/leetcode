class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int p = -1;
        for(int i = 0; i<nums.size(); i++){
            if(nums[i]){
                p += 1;
                swap(nums[i], nums[p]);
            }
        }
    }
};
