class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        vector<int> vec(nums.size(),0);
        for(int i = 0; i<nums.size(); i++){
            if(nums[i]>=s)
                return 1;
        }
       for(int i = 1; i<nums.size(); i++){
           for(int j = nums.size()-1; j>=i; j--){
               vec[j]  += nums[j-i];
               if(vec[j]>=s){
                   return (i+1);
               }
           }
       }
       return 0;
    }
};
