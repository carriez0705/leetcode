class Solution {
public:
    int innerfind(vector<int> &nums, int k, int left, int right){
        if(left==right && k ==1) return nums[left];
        int rnd = rand()%(right-left+1);
        swap(nums[left], nums[left+rnd]);
        int p = nums[left];
        int i = left, j = left+1;
        while(j<=right){
            if(nums[j]<p){
                swap(nums[++i],nums[j]);
            }
            j++;
        }
        swap(nums[i],nums[left]);
        if(right-i+1==k)
            return nums[i];
        else if(right-i+1<k)
            return innerfind(nums,k-right+i-1,left,i-1);
        else
            return innerfind(nums,k,i+1,right);
    }
    int findKthLargest(vector<int>& nums, int k) {
        if(!nums.size()) return 0;
        else return innerfind(nums,k,0,nums.size()-1);
    }
};
