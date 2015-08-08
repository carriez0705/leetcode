class Solution {
public:
    int calculateMinimumHP(vector<vector<int> > &dungeon) {
       int m = dungeon.size();
       if(!m) return 1;
       int n = dungeon[0].size();
       vector<vector<int> > d(m, vector<int>(n,0));
       d[m-1][n-1] = max(1-dungeon[m-1][n-1],1);
       int j = n-1;
       for(int i = m-2; i>=0; i--){
           d[i][j] = d[i+1][j];
           d[i][j] = max(d[i][j]-dungeon[i][j],1);
       }
       int i = m-1;
       for(int j= n-2; j>=0; j--){
           d[i][j] = d[i][j+1];
           d[i][j] = max(d[i][j]-dungeon[i][j],1);
       }
       for(int i = m-2; i>=0; i--)
            for(int j = n-2; j>=0; j--){
                d[i][j] = min(d[i+1][j], d[i][j+1]);
                d[i][j] = max(d[i][j]-dungeon[i][j],1);
            }
        return d[0][0];
    }
};
