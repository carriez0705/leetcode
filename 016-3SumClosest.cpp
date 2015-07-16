class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int closest = INT_MAX;
        sort(nums.begin(), nums.end());
        int sum = 0;
        for(int i = 0; i<nums.size()-2; i++){
            int j = i+1;
            int k = nums.size()-1;
            int res = target-nums[i];
            while(j<k){
                int temp = abs(res-nums[j]-nums[k]);
                if(!temp){
                    return target;
                }
                else{
                    if(closest>temp){
                        closest = temp;
                        sum = nums[i]+nums[j]+nums[k];
                    }
                    if(nums[j]+nums[k]<res)
                        j++;
                    else
                        k--;
                }
            }
        }
        return sum;
    }
};
