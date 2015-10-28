class Solution {
    int search(vector<int> &nums, int target, int begin, int end){
        if(begin>end)
            return begin;
        int mid = (begin+end)>>1;
        if(nums[mid]==target)
            return mid;
        else if(nums[mid]<target)
            return search(nums, target, mid+1, end);
        else
            return search(nums, target, begin, mid-1);
    }
public:
    int searchInsert(vector<int>& nums, int target) {
        return search(nums,target,0, nums.size()-1);
    }
};
