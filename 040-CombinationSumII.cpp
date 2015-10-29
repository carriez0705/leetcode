class Solution {
    set<vector<int> > result;
    void dfs(vector<int> &candidates, int target, int begin, vector<int> &vec){
        for(int i = begin; i<candidates.size(); i++){
            if(target==candidates[i]){
                vec.push_back(candidates[i]);
                result.insert(vec);
                vec.pop_back();
                return;
            }
            else if(target>candidates[i]){
                vec.push_back(candidates[i]);
                dfs(candidates, target-candidates[i], i+1, vec);
                vec.pop_back();
            }
            else
                return;
        }
    }
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        if(candidates.size())
            sort(candidates.begin(), candidates.end());
        result.clear();
        vector<int> vec;
        dfs(candidates, target, 0, vec);
        vector<vector<int> > ans(result.begin(), result.end());
        return ans;
    }
};
