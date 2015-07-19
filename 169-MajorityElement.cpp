class Solution {
public:
    int majorityElement(vector<int>& nums) {
        if(!nums.size()) return 0;
        if(nums.size()<=2) return nums[0];
        int i = 0, j = 1, p = -1;
        while(i<nums.size() && j<nums.size()){
            if(nums[i]!=nums[j]){
                swap(nums[p+1], nums[i]);
                swap(nums[p+2], nums[j]);
                p +=2;
            }
            i = max(i+1,p+1);
            j = max(j+1,p+2);
        }
        return nums[p+1];
    }
};
