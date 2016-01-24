class Solution {
public:
    vector<string> findMissingRanges(vector<int>& nums, int lower, int upper) {
        int low = lower;
        vector<string> ans;
        for(int i = 0; i<nums.size()&& nums[i]<=upper; i++){
            if(nums[i]>low){
                ans.push_back(pushstr(low, nums[i]-1));
            }
            low = nums[i]+1;
        }
        if(low<=upper){
            ans.push_back(pushstr(low,upper));
        }
        return ans;
    }
    string pushstr(int low, int upper){
        if(low==upper)
            return to_string(low);
        else
            return to_string(low)+"->"+to_string(upper);
    }
};
