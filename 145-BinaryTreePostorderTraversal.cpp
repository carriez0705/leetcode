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
    void stackpush(stack<TreeNode*> &nodstack, map<TreeNode*,int> &color, TreeNode* &node){
        nodstack.push(node);
        color[node] = 0;
    }
    vector<int> postorderTraversal(TreeNode* root) {
        stack<TreeNode*> nodstack;
        map<TreeNode*, int> color;
        vector<int> postorder;
        if(root) stackpush(nodstack, color, root);
        while(!nodstack.empty()){
            TreeNode *node = nodstack.top();
            if(!color[node]){
                if(node->right) stackpush(nodstack, color, node->right);
                if(node->left) stackpush(nodstack, color, node->left);
                color[node] = 1;
            }
            else{
                postorder.push_back(node->val);
                nodstack.pop();
            }
        }
        return postorder;
    }
};
