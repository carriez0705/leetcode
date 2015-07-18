class Solution {
public:
    int helper(vector<int> &nums, int left, int right){
        if(left>right) return -1;
        int mid = (left+right)>>1;
        int prev = mid>0?nums[mid-1]:INT_MIN;
        int next = mid<nums.size()-1? nums[mid+1]:INT_MIN;
        if(nums[mid]>=prev && nums[mid]>=next) return mid;
        if(nums[mid]>=prev){
            int pos=  helper(nums, left, mid-2);
            if(pos!=-1) return pos;
            return helper(nums, mid+1, right);
        }
        else{
            int pos = helper(nums, left, mid-1);
            if(pos!=-1) return pos;
            return helper(nums, mid+2, right);
        }
    }
    int findPeakElement(vector<int>& nums) {
        return helper(nums, 0, nums.size()-1);
    }
};
