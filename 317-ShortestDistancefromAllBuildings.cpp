class Solution {
    static int stepx[];
    static int stepy[];
public:
    int shortestDistance(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = m? grid[0].size() : 0;
        if(!m ||!n) return -1;
        vector<vector<int> > reach(m, vector<int>(n, 0));
        vector<vector<int> > distance(m, vector<int>(n, 0));
        int numHouse = 0;
        for(int i = 0; i<m; i++){
            for(int j = 0; j<n; j++){
                if(grid[i][j]==1){
                    numHouse++;
                    queue<pair<int, int> > que;
                    vector<vector<bool> > visited(m, vector<bool>(n, 0));
                    que.push(pair<int, int>(i, j));
                    visited[i][j] = 1;
                    
                    int dis = -1;
                    while(!que.empty()){
                        dis++;
                        int num = que.size();
                        for(int k = 0; k<num; k++){
                            int x = que.front().first;
                            int y = que.front().second;
                            distance[x][y]+=dis;
                            reach[x][y] += 1;
                            que.pop();
                            for(int p = 0; p<4; p++){
                                int nx = x +stepx[p];
                                int ny = y+ stepy[p];
                                if(nx>=0 && nx<m && ny>=0 &&ny<n && grid[nx][ny]==0 && !visited[nx][ny]){
                                    que.push(pair<int, int>(nx, ny));
                                    visited[nx][ny] = 1;
                                }
                            }
                        }
                        
                    }
                }
            }
        }
        int mindis = INT_MAX;
        for(int i = 0; i<m; i++){
            for(int j = 0; j<n; j++){
                if(grid[i][j]==0 && reach[i][j]==numHouse){
                    mindis = min(mindis, distance[i][j]);
                }
            }
        }
        return mindis==INT_MAX? -1 : mindis;
    }
};
int Solution::stepx[] = {0,1,0,-1};
int Solution::stepy[] = {1, 0, -1, 0};
