class Graph{
   int V, E;
   vector<vector<int> > adj;
   vector<int> degree;
public:
    Graph(int v, int e=0):V(v), E(e), adj(vector<vector<int> >(v, vector<int>())), degree(vector<int>(v, 0)){}
    void addEdge(int n1, int n2){
        adj[n2].push_back(n1);
        degree[n1]++;
        E++;
    }
    vector<int> printCourse(){
        //BFS
        vector<int> ans;
        queue<int> available;
        for(int i = 0;i<V; i++){
            if(degree[i]==0)
                available.push(i);
        }
        while(ans.size()<V){
            if(available.size()==0)
                return vector<int>();
            int node = available.front();
            ans.push_back(node);
            available.pop();
            for(int i = 0; i<adj[node].size(); i++){
                int nei = adj[node][i];
                degree[nei]--;
                if(degree[nei]==0)
                    available.push(nei);
            }
        }
        return ans;
    }
};
class Solution {
public:
    vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {
        if(!numCourses) return vector<int>();
        Graph gra(numCourses);
        for(int i = 0; i<prerequisites.size(); i++)
            gra.addEdge(prerequisites[i].first, prerequisites[i].second);
        return gra.printCourse();
    }
};


