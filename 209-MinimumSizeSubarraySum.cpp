class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
       int sum = 0;
       int start = 0;
       int minLen = INT_MAX;
       for(int i = 0; i<nums.size();i++){
           sum += nums[i];
           while(sum>=s){
               minLen = min(minLen, i-start+1);
               sum -= nums[start];
               start += 1;
           }
       }
       return minLen==INT_MAX?0:minLen;
    }
};

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
