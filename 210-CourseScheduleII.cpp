class Graph{
   int V, E;
   vector<vector<int> > adj;
   bool traverse(int node, vector<int> &mark, vector<int> &ans){
       mark[node] = 1;
       for(int i = 0; i<adj[node].size(); i++){
           int nei= adj[node][i];
           if(mark[nei]==1) return false;
           if(!mark[nei]){
               if(!traverse(nei, mark, ans))
                    return false;
           }
       }
       mark[node] = 2;
       ans.push_back(node);
       return true;
   }
public:
    Graph(int v, int e=0):V(v), E(e), adj(vector<vector<int> >(v, vector<int>())){}
    void addEdge(int n1, int n2){
        adj[n2].push_back(n1);
        E++;
    }
    vector<int> printCourse(){
        vector<int> ans;
        vector<int> mark(V, 0);
        for(int i = 0; i<V; i++){
            if(!mark[i]){
                if(!traverse(i, mark, ans)){
                    return vector<int>();
                }
            }
        }
        reverse(ans.begin(), ans.end());
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
