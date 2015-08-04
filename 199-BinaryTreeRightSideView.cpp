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
    vector<int> rightSideView(TreeNode* root) {
        map<TreeNode*, int> height;
        queue<TreeNode*> que;
        vector<int> ret;
        int curh = 0;
        if(root){
            que.push(root);
            height[root] = 0;
        }
        while(!que.empty()){
            TreeNode *node = que.front();
            que.pop();
            if(que.empty()||height[que.front()]!=curh){
                ret.push_back(node->val);
                curh += 1; //not height[que.front(0]
            }
            if(node->left){
                que.push(node->left);
                height[node->left] = height[node]+1;
            }
            if(node->right){
                que.push(node->right);
                height[node->right] = height[node]+1;
            }
        }
        return ret;
    }
};
