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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int> > level;
        queue<TreeNode*> nodqueue;
        map<TreeNode*, int> depth;
        int d = 0;
        if(root){
            nodqueue.push(root);
            depth[root] = 0;
        }
        else return level;
        vector<int> inner;
        while(!nodqueue.empty()){
            TreeNode* node = nodqueue.front();
            if(node->left){
                nodqueue.push(node->left);
                depth[node->left] = depth[node] + 1;
            }
            if(node->right){
                nodqueue.push(node->right);
                depth[node->right] = depth[node] +1;
            }
            nodqueue.pop();
            if(depth[node]!=d){
                level.push_back(inner);
                inner.clear();
                d = depth[node];
            }
            inner.push_back(node->val);
        }
        level.push_back(inner);
        return level;
    }
};
