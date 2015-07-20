class Solution {
public:
    int findPeak(vector<int> &nums, int lo, int hi){
        if(lo==hi) return lo;
        int mid = (lo+hi)>>1;
        if(nums[mid]>nums[mid+1]) return findPeak(nums,lo,mid);
        else return findPeak(nums, mid+1, hi);
    }
    int findPeakElement(vector<int>& nums) {
        if(!nums.size()) return INT_MIN;
        return findPeak(nums, 0, nums.size()-1);
    }
};
