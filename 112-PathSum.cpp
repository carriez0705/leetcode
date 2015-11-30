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
    bool dfs(TreeNode* node, int sum){
        if(!node){
            return false;
        }
        if(!node->left && !node->right){
            return sum==node->val;
        }
        return dfs(node->left, sum-node->val) || dfs(node->right, sum-node->val);
    }
public:
    bool hasPathSum(TreeNode* root, int sum) {
        return dfs(root, sum);
    }
};
