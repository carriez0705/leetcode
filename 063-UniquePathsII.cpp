class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = m==0? 0: obstacleGrid[0].size();
        if(!m || !n) return 0;
        vector<int> ans(n, 0);
        if(!obstacleGrid[0][0]) ans[0]=1;
        for(int i = 0; i<m; i++){
            for(int j = 0; j<n; j++){
                if(obstacleGrid[i][j]==0){
                    int left = j==0? 0 : ans[j-1];
                    ans[j] += left;
                }
                else
                    ans[j] = 0;
            }
        }
        return ans[n-1];
    }
};
