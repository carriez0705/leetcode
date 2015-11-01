class Solution {
    bool check(vector<int> &nums, int target, int begin, int end){
        if(begin>end) return true;
        int mid = (begin+end)>>1;
        if(nums[mid]!=target) return false;
        else return check(nums, target, begin, mid-1) && check(nums, target, mid+1, end);
    }
    int bst(vector<int> &nums, int target, int begin, int end){
        if(begin>end)
            return -1;
        int mid = (begin+end)>>1;
        if(nums[mid]==target)
            return mid;
        else if(nums[mid]==nums[begin] && nums[mid]==nums[end]){
            if(check(nums, nums[mid], begin, mid))
                return bst(nums, target, mid+1, end);
            else
                return bst(nums, target, begin, mid-1);
        }
        else if(nums[begin]<=nums[mid]){
            if(target>=nums[begin] && target<nums[mid])
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
    bool search(vector<int>& nums, int target) {
        return bst(nums, target, 0, nums.size()-1)!=-1;
    }
};
