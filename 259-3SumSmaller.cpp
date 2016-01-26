class Solution {
public:
    int threeSumSmaller(vector<int>& nums, int target) {
        if(nums.size()<3) return 0;
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int count = 0;
        for(int i = 0; i<n-2; i++){
            int p = i+1, q = n-1;
            while(p<q){
                if(nums[i]+nums[p]+nums[q]<target){
                    count += q-p;
                    p++;
                }
                else{
                    q--;
                }
            }
        }
        return count;
    }
};
