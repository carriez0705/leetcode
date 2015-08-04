class Solution {
public:
    void maze(vector<vector<char> > &grid, vector<vector<char> > &color, int i, int j){
        if(grid[i][j]=='0'||color[i][j]==1)
            return;
        color[i][j] = 1;
        if(j+1<grid[0].size())
            maze(grid, color, i, j+1);
        if(i+1<grid.size())
            maze(grid, color, i+1, j);
        if(j-1>=0)
            maze(grid, color, i, j-1);
        if(i-1>=0)
            maze(grid, color, i-1, j);
    }
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        if(!n) return 0;
        int m = grid[0].size();
        vector<vector<char> > color(n, vector<char>(m,0));//0: uncultivated; 1:cultivated
        int count = 0;
        for(int i = 0; i<n; i++)
            for(int j = 0;j<m; j++){
                if(grid[i][j]=='1'&&color[i][j]==0){
                    maze(grid, color, i, j);
                    count += 1;
                }
            }
       return count;     
    }
};
