class DiGraph{
    int V;
    int E;
    vector<char> mark;
    vector<vector<int> > adj;
public:
    DiGraph(int n, string &s):V(n),E(0){
        adj.clear();
        adj.resize(n);
        mark.clear();
        mark.resize(n);
        for(int i = 0; i<s.size(); i++){
            vetex.push_back(s[i]);
        }
    }
    void addEdge(int p, int q){
        adj[p].push_back(q);
        E += 1;
    }
    void dfs(int i, set<int> &reach){
        mark[i] = 1;
        for(int k =0; k<adj[i].size();k++){
            int c = adj[i][k];
            if(!mark[c]){
                reach.insert(c);
                dfs(c,reach);
            }
        }
        mark[i] = 2;
    }
    void directdfs(set<int> &vset, set<int> &reach){
        for(int i = 0; i<V; i++)
            mark[i] = 0;
        reach = vset;
        for(auto iter = vset.begin(); iter!=vset.end(); iter++)
            dfs(*iter, reach);
    }
    vector<char> vetex;
};
class Solution {
    
public:
    bool isMatch(string s, string p) {
        if(!p.size()&&s.size()) return false;
        DiGraph graph(p.size()+1,p);
        for(int i = 0; i<p.size(); i++){
            if(p[i]=='*'&&i){
                graph.addEdge(i-1,i);
                graph.addEdge(i,i-1);
                graph.addEdge(i,i+1);
            }
        }
        set<int> reach;
        set<int> vset;
        vset.insert(0);
        graph.directdfs(vset,reach);
        for(int i = 0;i<s.size();i++){
            vset.clear();
            for(auto iter = reach.begin(); iter!=reach.end()&&*iter<p.size(); iter++){
                if(s[i]==graph.vetex[*iter]||graph.vetex[*iter]=='.')
                    vset.insert(*iter+1);
            }
            graph.directdfs(vset, reach);
        }
        for(auto iter = reach.begin(); iter!=reach.end(); iter++)
            if(*iter==p.size()) return true;
        return false;
    }
};
