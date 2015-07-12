class Solution {
public:
    int find(vector<int> &nums, int left, int right){
        if(left==right) return nums[left];
        if(left+1==right) return min(nums[left], nums[right]);
        int mid = (left+right)>>1;
        if(nums[left]>nums[mid])
            return find(nums, left, mid);
        else if(nums[mid]>nums[right])
            return find(nums, mid, right);
        else return nums[left];
    }
    int findMin(vector<int>& nums) {
        return find(nums, 0, nums.size()-1);
    }
};
