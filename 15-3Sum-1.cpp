class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int> > result;
        if(nums.size()<3) return result;
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int k = 0, i=1, j = n-1;
        for(;k<=nums.size()-3; k++){
            while(k && nums[k]==nums[k-1])
                k++;
            i = k+1;
            j = n-1;
            
            while(i<j){
                int sum = 0-nums[i]-nums[j];
                if(nums[k]==sum){
                    vector<int> vec;
                    vec.push_back(nums[k]);
                    vec.push_back(nums[i]);
                    vec.push_back(nums[j]);
                    result.push_back(vec);
                    i++;
                    j--;
                }
                else if(nums[k]<sum){
                    i++;
                }
                else{
                    j--;
                }
                while(i>k+1 && i<n && nums[i] ==nums[i-1])
                    i++;
                while(j>k && j<n-1 && nums[j]==nums[j+1])
                    j--;
            }
           
        }
        return result;
    }
};
