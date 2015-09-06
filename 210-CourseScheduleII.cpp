//enum color = {WHITE, GRAY, BLACK};
class Solution {
public:
    bool dfs(int node, vector<vector<int> > &adj, vector<char> &color,vector<int> &result){
        color[node] = 1;
        for(int i = 0; i<adj[node].size();i++){
            int ch = adj[node][i];
            if(color[ch]==1) return false;
            if(!color[ch])
                if(!dfs(ch,adj,color,result)) return false;;
        }
        color[node] = 2;
        result.push_back(node);
        return true;
    }
    vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector<vector<int> > adj(numCourses, vector<int>());
        vector<char> color(numCourses,0);
        vector<int> result;
        for(int i = 0; i<prerequisites.size();i++){
            adj[prerequisites[i].first].push_back(prerequisites[i].second);
        }
        bool f = true;
        for(int i = 0; i<adj.size();i++){
            if(!color[i])
                if(!dfs(i,adj, color, result)) return vector<int>();
        }
        return result;
    }
};
