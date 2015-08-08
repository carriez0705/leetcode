class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        if(!m) return 0;
        int n = obstacleGrid[0].size();
        vector<vector<int> > way(m, vector<int>(n,0));
        if(!obstacleGrid[0][0]) way[0][0] = 1;
        for(int i =1; i<m; i++)
            if(obstacleGrid[i][0])
                way[i][0] = 0;
            else
                way[i][0] = way[i-1][0];
        for(int j = 1; j<n; j++)
            if(obstacleGrid[0][j])
                way[0][j] = 0;
            else
                way[0][j] = way[0][j-1];
        for(int i = 1; i<m; i++)
            for(int  j = 1; j<n; j++){
                if(obstacleGrid[i][j])
                    way[i][j] = 0;
                else
                    way[i][j] = way[i-1][j]+way[i][j-1];
            }
        return way[m-1][n-1];
    }
};
