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
    int dfs(TreeNode *node, int &maxsum){
        if(!node) return 0;
        int leftsum = max(0, dfs(node->left, maxsum));
        int rightsum = max(0, dfs(node->right, maxsum));
        maxsum = max(maxsum,  node->val+leftsum+rightsum);
        return node->val+max(leftsum, rightsum);
    }
public:
    int maxPathSum(TreeNode* root) {
        int maxsum = INT_MIN;
        dfs(root, maxsum);
        return maxsum;
    }
};
