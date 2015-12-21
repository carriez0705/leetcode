
class Solution {
    void pushleaves(unordered_map<int, int> &degree, queue<int> &que){
        for(auto iter = degree.begin(); iter!=degree.end(); iter++){
            if(iter->second==1 || iter->second==0)
                que.push(iter->first);
        }
    }
    void topologicalSort(int n, unordered_map<int, int> &degree, vector<vector<int> > &neighbor, vector<int> &ans){
       queue<int> que;
       pushleaves(degree, que);
       while(!que.empty()){
           if(degree.size()==1 || degree.size()==2){
               while(!que.empty()){
                   ans.push_back(que.front());
                   que.pop();
               }
               return;
           }
           int k = que.size();
           for(int i = 0; i<k; i++){
               int node = que.front();
               que.pop();
               degree.erase(node);
               for(int j = 0; j<neighbor[node].size(); j++){
                   int nei = neighbor[node][j];
                   if(degree.find(nei)!=degree.end())
                        degree[nei] -= 1;
               }
           }
           pushleaves(degree, que);
       }
    }
public:
    vector<int> findMinHeightTrees(int n, vector<pair<int, int>>& edges) {
        if(!n) return vector<int>();
        vector<vector<int> > neighbor(n, vector<int>());
        for(int i = 0; i<edges.size(); i++){
            int node1 = edges[i].first;
            int node2 = edges[i].second;
            neighbor[node1].push_back(node2);
            neighbor[node2].push_back(node1);
        }
        unordered_map<int, int> degree;
        for(int i = 0; i<n; i++){
            degree[i] = neighbor[i].size();
        }
        vector<int> ans;
        topologicalSort(n,degree, neighbor, ans);
        return ans;
    }
};
