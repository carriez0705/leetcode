//solution 1- binary search
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int left = 1, right = nums.size()-1;
        while(left<right){
            int mid = (left+right)>>1;
            int count = 0;
            for(int i = 0; i<nums.size(); i++){
                if(nums[i]<=mid) count+= 1;
            }
            if(count>mid) right = mid;
            else left = mid+1;
        }
        return right;
    }
};
/solution 2 -fast slow pointer
class Solution{
public:
    int findDuplicate(vector<int>& nums)
    {
        int fast = nums[nums[0]], slow = nums[0];
        while(fast!=slow){
            fast = nums[nums[fast]];
            slow = nums[slow];
        }
        fast = 0;
        while(fast!=slow){
            fast = nums[fast];
            slow = nums[slow];
        }
        return slow;
    
    }
};
