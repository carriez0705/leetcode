class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int one = 0, two= 0;
        for(int i = 0;i<nums.size();i++){
            int temp = two;
            two = one&nums[i] | (two&(~nums[i]));
            one = (~temp &nums[i])^one;
        }
        return one;
    }
};
