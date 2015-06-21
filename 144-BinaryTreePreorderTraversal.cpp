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
    vector<int> preorderTraversal(TreeNode* root) {
        stack<TreeNode*> nodstack;
        vector<int> preorder;
        if(root) nodstack.push(root);
        while(!nodstack.empty()){
            TreeNode* node = nodstack.top();
            preorder.push_back(node->val);
            nodstack.pop();
            if(node->right) nodstack.push(node->right);
            if(node->left) nodstack.push(node->left);
        }
        return preorder;
    }
};
