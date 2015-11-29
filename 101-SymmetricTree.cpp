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
    bool symmetric(TreeNode *node1, TreeNode *node2){
        if(!node1 && !node2) return true;
        if(!node1 || !node2) return false;
        return node1->val==node2->val && symmetric(node1->left, node2->right) && symmetric(node1->right, node2->left);
    }
public:
    bool isSymmetric(TreeNode* root) {
        if(!root) return true;
        return symmetric(root->left, root->right);
    }
};
