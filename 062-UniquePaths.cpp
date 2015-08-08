class Solution {
public:
    int uniquePaths(int m, int n) {
        if(!m) return 0;
        vector<vector<int> > way(m, vector<int>(n,0));
        for(int i = 0; i<m; i++)
            way[i][0] = 1;
        for(int j = 0; j<n; j++)
            way[0][j] = 1;
        for(int i = 1; i<m; i++)
            for(int j = 1; j<n; j++){
                way[i][j] = way[i-1][j]+way[i][j-1];
            }
        return way[m-1][n-1];
    }
};
