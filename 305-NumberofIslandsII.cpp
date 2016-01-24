class Solution {
    static int stepx[];
    static int stepy[];
public:
    vector<int> numIslands2(int m, int n, vector<pair<int, int>>& positions) {
        if(!m || !n) return vector<int>();
        vector<int> root(m*n, -1);
        vector<int> ans;
        int count = 0;
        for(int i = 0; i<positions.size(); i++){
            int x = positions[i].first;
            int y = positions[i].second;
            int id = x*n+y;
            root[id] = id;
            count++;
            for(int k = 0; k<4; k++){
                int nx = x+stepx[k];
                int ny = y+stepy[k];
                if(nx>=0 && nx<m &&ny>=0 &&ny<n &&root[nx*n+ny]!=-1){
                    int p = unionIsland(root, nx*n+ny);
                    if(p!=root[id]){
                        root[id] =p;
                        count--;
                        id = root[id];
                    }
                }
            }
            ans.push_back(count);
        }
        return ans;
    }
    int unionIsland(vector<int> &root, int id){
        while(root[id]!=id){
            root[id] = root[root[id]];
            id = root[id];
        }
        return id;
    }
};
int Solution::stepx[] ={0,1,0,-1};
int Solution::stepy[] = {1, 0,-1,0};
