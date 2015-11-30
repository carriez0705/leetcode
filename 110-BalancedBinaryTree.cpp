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
    bool balance(TreeNode * root, int &h){
        if(!root){
            h = 0;
            return true;
        }
        int leftH = 0, rightH = 0;
        bool l = balance(root->left, leftH);
        bool r = balance(root->right, rightH);
        h = max(leftH, rightH)+1;
        return l && r && abs(leftH-rightH)<=1;
    }
public:
    bool isBalanced(TreeNode* root) {
        if(!root) return true;
        int h1=0, h2= 0;
        if(balance(root->left, h1) && balance(root->right, h2)){
            return abs(h1-h2)<=1;
        }
        return false;
    }
};
