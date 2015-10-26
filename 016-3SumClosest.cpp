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

//2015-10-25
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int n = nums.size();
        if(!n) return 0;
        sort(nums.begin(), nums.end());
        int mingap = INT_MAX;
        int closest = 0;
        for(int i = 0; i<nums.size()-2; i++){
            if(i>0 && nums[i]==nums[i-1])
                continue;
            int res = target-nums[i];
            int p = i+1;
            int q = nums.size()-1;
            while(p<q){
            int sum = nums[p]+nums[q];
            int r = abs(sum-res);
            if(r<mingap){
                mingap = r;
                closest = sum+nums[i];
            }
            if(sum==res){
                return closest;
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
        return closest;
    }
};
