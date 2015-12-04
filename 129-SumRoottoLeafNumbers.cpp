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
    void dfs(TreeNode *node, int &sum, int &pathsum){
        pathsum = pathsum*10+node->val;
        if(!node->left && !node->right){
            sum += pathsum;
            pathsum = pathsum/10;
            return;
        }
        if(node->left){
            dfs(node->left, sum, pathsum);
        }
        if(node->right){
            dfs(node->right, sum, pathsum);
        }
        pathsum = pathsum/10;
    }
public:
    int sumNumbers(TreeNode* root) {
        if(!root) return 0;
        int pathsum = 0, sum = 0;
        dfs(root, sum, pathsum);
        return sum;
    }
};
