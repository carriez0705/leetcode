class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int all = 0, others = 0;
        int min_ = INT_MAX, max_ = INT_MIN;
        for(int i = 0; i<nums.size(); i++){
            min_ = min(min_, nums[i]);
            max_ = max(max_, nums[i]);
            others ^= nums[i];
        }
        for(int i = min_;i<=max_; i++)
            all ^= i;
        int single = all^others;
        if(!single) return min_==0?max_+1:0;
        else return single;
    }
};
