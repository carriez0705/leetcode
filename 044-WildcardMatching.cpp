class DGraph{
    //vector<int> vertex;
    string pattern;
    int vertexNum;
    unordered_map<int, vector<int> > adj;
    void addEdge(int v1, int v2){
        if(adj.find(v1)==adj.end())
            adj[v1] = vector<int>(1,v2);
        else{
            adj[v1].push_back(v2);
        }
    }
    void dfs(int v, vector<int> &reachable, vector<bool> &color){
        color[v] = true;
        reachable.push_back(v);
        if(adj.find(v)==adj.end()) return;                            
        for(int i = 0; i<adj[v].size(); i++){
            int neighbor = adj[v][i];
            if(!color[neighbor]){
                dfs(neighbor, reachable, color);
            }
        }
    }
public:
    DGraph(string p):pattern(p){
        vertexNum = p.size();
        for(int i = 0; i<p.size(); i++){
            if(p[i]=='*'){
                addEdge(i, i+1);
                addEdge(i+1, i);
            }
        }
    }
    vector<int> reach(vector<int> &candidates){
        vector<int> reachable;
        vector<bool> color(vertexNum+1, false);
        for(int i = 0; i<candidates.size(); i++){
                dfs(candidates[i], reachable, color);
        }
        return reachable;
    }
};
class Solution {
public:
    bool isMatch(string s, string p) {
        DGraph dg(p);
        vector<int> candidates;
        candidates.push_back(0); 
        for(int i = 0; i<s.size(); i++){
            vector<int> reachable = dg.reach(candidates);
            candidates.clear();
            for(int j = 0; j<reachable.size(); j++){
                if(reachable[j]<p.size() && (p[reachable[j]]=='*' || p[reachable[j]]=='?' || s[i]==p[reachable[j]])){
                    candidates.push_back(reachable[j]+1);
                }
            }
        }
        vector<int> reachable = dg.reach(candidates);
        for(int i = 0; i<reachable.size(); i++){
            if(reachable[i]==p.size())
                return true;
        }
        return false;
    }
};
