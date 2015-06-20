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
    bool findInverted(TreeNode *&previous, TreeNode *node, TreeNode *&first, TreeNode *&second){
        if(!node) return false;
        if(findInverted(previous, node->left, first, second))
            return true;
        if(previous->val > node->val){
            second = node;
            if(!first){
                first = previous; 
            }
            else{
                return true;
            }
        }
        previous = node;
        return findInverted(previous, node->right, first, second);
    }
    void recoverTree(TreeNode* root) {
        TreeNode *first = NULL, *second = NULL;
        TreeNode temp = TreeNode(INT_MIN);
        TreeNode *previous = &temp;
        findInverted(previous, root, first, second);
        if(first)
            swap(first->val, second->val);
    }
};
