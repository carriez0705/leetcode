class Solution {
    void dfs(vector<int> &nums, vector<bool> &used, vector<int> &vec, vector<vector<int> > &perm){
        int n = nums.size();
        if(vec.size()==n){
            perm.push_back(vec);
            return;
        }
        for(int i = 0; i<n; i++){
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
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> vec;
        vector<vector<int> > perm;
        if(!nums.size()) return perm;
        vector<bool> used(nums.size(), false);
        dfs(nums, used, vec, perm);
        return perm;
    }
};
