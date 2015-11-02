class Solution {
    vector<vector<int> > result;
    void combine(vector<int> &candidates, int target, int begin, vector<int> &vec){
        for(int i = begin; i<candidates.size(); i++){
            if(i!=0 && candidates[i]==candidates[i-1])
                continue;
            if(candidates[i]==target){
                vec.push_back(candidates[i]);
                result.push_back(vec);
                vec.pop_back();
                return;
            }
            else if(candidates[i]<target){
                vec.push_back(candidates[i]);
                combine(candidates, target-candidates[i], i, vec);
                vec.pop_back();
            }
            else
                return;
        }
    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        if(candidates.size())
            sort(candidates.begin(), candidates.end());
        result. clear();
        vector<int> vec;
        combine(candidates, target, 0, vec);
        return result;
    }
};
