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
    TreeNode* dfs(TreeNode *node, int t1, int t2){
        int t = node->val;
        if(t>=t1 && t<=t2)
            return node;
        if(t<t1&&node->right)
            return dfs(node->right, t1,t2);
        if(t>t2&&node->left)
            return dfs(node->left, t1, t2);
        return NULL;
            
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root) return NULL;
        int t1 = min(p->val,q->val);
        int t2 = max(p->val,q->val);
        return dfs(root, t1, t2);
    }
};
