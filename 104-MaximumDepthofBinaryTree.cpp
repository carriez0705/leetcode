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
    int dfs(TreeNode *node, int level){
        if(!node) return level-1;
        return max(dfs(node->left, level+1), dfs(node->right, level+1));
    }
public:
    int maxDepth(TreeNode* root) {
        return dfs(root, 1);
    }
};
