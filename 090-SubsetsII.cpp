class Solution {
    void dfs(vector<int> &nums, int begin, vector<int> &vec, vector<vector<int> > &ans){
        ans.push_back(vec);
        for(int i = begin; i<nums.size(); i++){
            if(i>begin && nums[i]==nums[i-1])
                continue;
            vec.push_back(nums[i]);
            dfs(nums, i+1, vec, ans);
            vec.pop_back();
        }
    }
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int> vec;
        vector<vector<int> > ans;
        if(!nums.size()) return ans;
        sort(nums.begin(), nums.end());
        dfs(nums, 0, vec, ans);
        return ans;
    }
};
