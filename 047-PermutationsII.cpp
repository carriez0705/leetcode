class Solution {
    void dfs(vector<int> &nums, vector<bool> &used, vector<int> &vec, vector<vector<int> > &perm){
        int n = nums.size();
        if(n==vec.size()){
            perm.push_back(vec);
            return;
        }
        for(int i = 0; i<n; i++){
            if(i!=0 && nums[i]==nums[i-1] && !used[i-1])
                continue;
            if(!used[i]){
                vec.push_back(nums[i]);
                used[i] = true;
                dfs(nums, used, vec, perm);
                used[i] = false;
                vec.pop_back();
            }
        }
    }
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int> > perm;
        if(!nums.size()) return perm;
        vector<int> vec;
        vector<bool> used(nums.size(), false);
        sort(nums.begin(), nums.end());
        dfs(nums, used, vec, perm);
        return perm;
    }
};
