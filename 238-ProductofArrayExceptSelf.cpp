class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> result;
        int prod = 1;
        for(int i = 0;i<nums.size();prod *= nums[i], i++)
            result.push_back(prod);
        for(int i = nums.size()-1,prod = 1;i>=0;prod *= nums[i], i--)
            result[i] *= prod;
        return result;
    }
};
