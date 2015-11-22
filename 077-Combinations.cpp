class Solution {
    void dfs(int n, int start, int k, vector<int> &vec, vector<vector<int> > &ans){
        if(vec.size()==k){
            ans.push_back(vec);
            return;
        }
        for(int i = start; i<=n; i++){
            vec.push_back(i);
            dfs(n, i+1, k, vec, ans);
            vec.pop_back();
        }
    }
public:
    vector<vector<int>> combine(int n, int k) {
        vector<int> vec;
        vector<vector<int> > ans;
        dfs(n, 1, k, vec, ans);
        return ans;
    }
};
