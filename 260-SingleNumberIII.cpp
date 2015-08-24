class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int axorb = 0;
        for(int i = 0; i<nums.size(); i++)
            axorb ^= nums[i];
        int last = (axorb&(axorb-1))^axorb;
        int a = 0,b=0;
        for(int i = 0; i<nums.size(); i++){
            if(nums[i]&last) a ^= nums[i];
            else b ^= nums[i];
        }
        vector<int> result;
        result.push_back(a);
        result.push_back(b);
        return result;
    }
};
