class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int> > ans;
        if(numRows==0) return ans;
        for(int i = 0; i<numRows; i++){
            vector<int> level;
            for(int j = 0; j<=i; j++){
                if(j==0 || j==i)
                    level.push_back(1);
                else{
                    level.push_back(ans[i-1][j-1] + ans[i-1][j]);
                }
            }
            ans.push_back(level);
        }
        return ans;
    }
};
