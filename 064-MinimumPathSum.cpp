class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        if(!m) return 0;
        int n = grid[0].size();
        vector<vector<int> > way(m, vector<int>(n,0));
        way[0][0] = grid[0][0];
        for(int i = 1; i<m; i++)
            way[i][0] = way[i-1][0]+grid[i][0];
        for(int j = 1; j<n; j++)
            way[0][j] = way[0][j-1] + grid[0][j];
        for(int i = 1; i<m; i++)
            for(int j = 1; j<n; j++)
                way[i][j] = min(way[i-1][j], way[i][j-1])+grid[i][j];
        return way[m-1][n-1];
    }
};
