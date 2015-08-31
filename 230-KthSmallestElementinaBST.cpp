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
    void inorder(TreeNode* node, int k, int &n, TreeNode *&answer){
        if(node->left)
            inorder(node->left,k,n,answer);
        n = n+1;
        if(n==k){
            answer = node;
            return;
        }
        if(!answer && node->right)
            inorder(node->right, k, n, answer);
    }
    int kthSmallest(TreeNode* root, int k) {
        if(!root) return 0;
        TreeNode *answer = NULL;
        int n = 0;
        inorder(root, k, n, answer);
        if(answer) return answer->val;
        else return 0;
    }
};

//follow up: add int chnum in TreeNode data structure to record number of its predecessors and itself
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     int chnum;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL), chnum(0) {}
 * };
 */
class Solution {
public:
    void helper(TreeNode *node, int k, TreeNode* &answer){
        if(k>node->chnum) return;
        int left = node->left?node->left->chnum:0;
        if(left+1==k){
            answer = node;
            return;
        }
        else if(k<=left)
            helper(node->left, k, answer);
        else
            helper(node->right, k-left-1, answer);
    }
    int kthSmallest(TreeNode* root, int k) {
        if(!root) return 0;
        TreeNode *answer = NULL;
        helper(root, k, answer);
        if(answer) return answer->val;
        else return 0;
    }
};
