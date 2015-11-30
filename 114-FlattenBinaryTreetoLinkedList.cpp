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
    void build(TreeNode* node, TreeNode *&pre){
        if(!node) return;
        if(pre){
            pre->right = node;
            pre->left = NULL;
        }
        pre = node;
        TreeNode *rightTree = node->right;
        build(node->left, pre);
        build(rightTree, pre);
    }
public:
    void flatten(TreeNode* root) {
        TreeNode *pre = NULL;
        build(root, pre);
    }
};
