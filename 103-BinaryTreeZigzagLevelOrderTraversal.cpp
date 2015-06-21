/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void queuePush(queue<TreeNode*> &nodqueue, map<TreeNode*, int> &depth, TreeNode* &root, TreeNode* &child){
            nodqueue.push(child);
            depth[child] = depth[root] + 1;
    }
    void zagvert(vector<int> &inner){
        auto i = inner.begin();
        auto j = inner.begin()+inner.size()-1;
        while(i<j) swap(*i++, *j--);
    }
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int> > zigzag;
        queue<TreeNode*> nodqueue;
        map<TreeNode*, int> depth;
        int d = 0;
        bool zag = false;
        if(root){
            nodqueue.push(root);
            depth[root] = 0;
        }
        else
            return zigzag;
        vector<int> inner;
        while(!nodqueue.empty()){
            TreeNode *node = nodqueue.front();
            if(depth[node]!=d){
                if(zag) zagvert(inner);
                zigzag.push_back(inner);
                inner.clear();
                d = depth[node];
                zag = !zag;
            }
            inner.push_back(node->val);
            nodqueue.pop();
            if(node->left) queuePush(nodqueue, depth, node, node->left);
            if(node->right) queuePush(nodqueue, depth, node, node->right);
        }
        if(zag) zagvert(inner);
        zigzag.push_back(inner);
        return zigzag;
    }
};
