class Solution {
    int bst(vector<int> &nums, int target, int begin, int end){
        if(begin>end) return -1;
        int mid = (begin+end)>>1;
        if(nums[mid]==target)
            return mid;
        else if(nums[begin]<=nums[mid]){
            if(target<nums[mid] && target>=nums[begin])
                return bst(nums, target, begin, mid-1);
            else
                return bst(nums, target, mid+1, end);
        }
        else{
            if(target>nums[mid] && target<=nums[end])
                return bst(nums, target, mid+1, end);
            else
                return bst(nums, target, begin, mid-1);
        }
    }
public:
    int search(vector<int>& nums, int target) {
        return bst(nums, target, 0, nums.size()-1);
    }
};
