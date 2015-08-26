class Solution {
public:
    bool dfs(vector<vector<int> > &adj, vector<char> &color, int node){
        for(int i = 0; i<adj[node].size(); i++){
            int c = adj[node][i];
            if(color[c]==1) return false;
            if(color[c]==0){
                color[c] = 1;
                if(!dfs(adj, color, c)) return false;
                color[c]=2;
            }
        }
        return true;
    }
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
        if(!numCourses) return prerequisites.size()==0;
        vector<char> color(numCourses,0);
        vector<vector<int> > adj(numCourses, vector<int>());
        for(int i = 0; i<prerequisites.size();i++){
            adj[prerequisites[i].first].push_back(prerequisites[i].second);
        }
        for(int i = 0; i<adj.size(); i++){
            if(color[i]==0&&adj[i].size()>0){
                if(!dfs(adj,color,i)) return false;
            }
        }
        return true;
    }
};
