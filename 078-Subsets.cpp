class Solution {
    void dfs(vector<int> &nums, int start, vector<int> &vec, vector<vector<int> > &ans){
        ans.push_back(vec);
        for(int i = start; i<nums.size(); i++){
            vec.push_back(nums[i]);
            dfs(nums, i+1, vec, ans);
            vec.pop_back();
        }
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> vec;
        vector<vector<int> > ans;
        dfs(nums, 0, vec, ans);
        return ans;
    }
};
