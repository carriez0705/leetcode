class Solution {
public:
    void replace(vector<int> &nums, int lo, int hi, int k){
        while(k>0){
            swap(nums[lo], nums[hi]);
            lo++;
            hi++;
            k--;
        }
    }
    void shift(vector<int> &nums, int lo, int hi, int k){
        k = k%(hi-lo+1);
        if(lo>=hi || !k) return;
        if(k<=(hi-lo+1)/2){
            replace(nums,lo, hi-k+1, k);
            shift(nums, lo+k, hi, k);
        }
        else{
            k = hi-lo+1-k;
            replace(nums,lo, hi-k+1, k);
            shift(nums, lo, hi-k, hi-k-lo+1-k);
        }
    }
    void rotate(vector<int>& nums, int k) {
        k = k%nums.size();
        if(!nums.size()|| !k) return;
        shift(nums, 0, nums.size()-1, k);
    }
};
