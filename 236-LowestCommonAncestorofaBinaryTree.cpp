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
    TreeNode* dfs(TreeNode *node, TreeNode *&p, TreeNode *&q, bool &f){
        TreeNode *root = NULL, *l = NULL, *r = NULL;
        if(node==p||node==q)
            root = node;
        if(node->left)
            l = dfs(node->left, p, q, f);
        if(!f&&node->right)
            r = dfs(node->right, p,q, f);
        if(l&&r){
            f = true;
            return node;
        }
        f = root&&(l||r);
        if(root) return root;
        if(l) return l;
        if(r) return r;
        return NULL;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root) return NULL;
        bool f = false;
        return dfs(root, p, q, f);
    }
};
