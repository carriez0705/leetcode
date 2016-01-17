dp[i][j] += dp[i-1][j-nums[i]*t]
int find(vecrtor<int> &candidates, int s){
    unordered_map<int, int> nums;
    for(int i = 0; i<candidates.size(); i++){
        nums[candidates[i]]++;
    }
    vector<vector<int> > dp(nums.size(), vector<int>(s+1, 0));
    for(int i = 0; i<nums.size(); i++)
        dp[i][0] = 1;
    int i =0;
    for(auto iter = nums.begin(); iter!=nums.end(); iter++, i++){
        int num = iter->first;
        int count = iter->second;
        for(int j = 1; j<=s; j++){
            int t = 1;
            while(t<=count){
                if(j-num*t>=0)
                    dp[i][j] += dp[i-1][j-num*t];
                else break;
                t++;
            }
        }
    }
    return dp[nums.size()-1][s];
}
int find(vector<int> &candidates, int s){
    sort(candidates.begin(), candidates.end());
    vector<int> dp(s+1, 0);
    dp[0] = 1;
    for(int i = 0; i<candidates.size(); i=nexti){
        int nexti = i+1;
        while(nexti<candidates.size() && candidates[nexti]==candidates[i]){nexti++;}
        int tot = nexti-i;
        for(int j = s; j>0; j--){
            int t = 1;
            while(t<=tot && j-candidates[i]*t>=0){
                dp[j] += dp[j-candidates[i]*t];
                t++;
            }
        }
    }
    return dp[s];
}
