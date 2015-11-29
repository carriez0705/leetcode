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
    bool valid(TreeNode *node, long long begin, long long end){
        if(!node) return true;
        if(node->val <= begin || node->val >= end ) return false;
        return valid(node->left, begin, node->val) && valid(node->right, node->val, end);
    }
    
public:
    bool isValidBST(TreeNode* root) {
        long long min_ = (long long)INT_MIN-1;
        long long max_ = (long long)INT_MAX+1;
        return valid(root, min_, max_);
    }
};
