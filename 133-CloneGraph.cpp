/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */
class Solution {
public:
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        unordered_map<UndirectedGraphNode*, UndirectedGraphNode*> copy;
        queue<UndirectedGraphNode*> que;
        if(!node) return NULL;
        que.push(node);
        UndirectedGraphNode* newnode = new UndirectedGraphNode(node->label);
        UndirectedGraphNode* root = newnode;
        copy[node] = newnode;
        while(!que.empty()){
            UndirectedGraphNode *node = que.front();
            que.pop();
            for(int i = 0; i<node->neighbors.size(); i++){
                UndirectedGraphNode *n = node->neighbors[i];
                //check if existed!!
                if(copy.find(n)==copy.end()){
                    que.push(n);
                    newnode = new UndirectedGraphNode(n->label);
                    copy[n] = newnode;
                }
                copy[node]->neighbors.push_back(copy[n]);
            }
        }
        return root;
    }
};
