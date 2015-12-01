
int count(vector<int> &candidates, int target){
        vector<int> cvec(target+1, 0);
        cvec[0] = 1;
        sort(candidates.begin(), candidates.end());
        int identical = 0;
        for(int i = 0; i<candidates.size(); i++){
            if(i>0 && candidates[i]==candidates[i-1]){
                identical++;
            }
            else
                identical = 0;
            for(int j = target; j>=max(candidates[i], candidates[i]*identical+1); j--){
                cvec[j] += cvec[j-candidates[i]];
            }
        }
        return cvec[target];
    }
