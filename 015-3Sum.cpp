class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int> > result;
        if(!nums.size()) return result;
        sort(nums.begin(), nums.end());
        for(int i = 0; i<=nums.size()-3 && nums[i]<=0 ;i++){
            if(i>0 && nums[i]==nums[i-1])
                continue;
            int p = i+1, q = nums.size()-1;
            int res = 0-nums[i];
            while(p<q){
                int sum = nums[p]+nums[q];
                if(sum==res){
                    vector<int> vec;
                    vec.push_back(nums[i]);
                    vec.push_back(nums[p]);
                    vec.push_back(nums[q]);
                    result.push_back(vec);
                    while(nums[p+1]==nums[p])
                        p++;
                    p++;
                    while(nums[q-1]==nums[q])
                        q--;
                    q--;
                }
                else if(sum<res){
                    while(nums[p+1]==nums[p])
                        p++;
                    p++;
                }
                else{
                    while(nums[q-1]==nums[q])
                        q--;
                    q--;
                }
            }
        }
        return result;
    }
};
