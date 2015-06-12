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
    void dfs(TreeNode *r){
        TreeNode *nl = r->left;
        TreeNode *nr = r->right;
        r->right = nl;
        r->left = nr;
        if(nl)
            dfs(nl);
        if(nr)
            dfs(nr);
    }
    TreeNode* invertTree(TreeNode* root) {
        if(!root) return root;
        dfs(root);
        return root;
    }
};
