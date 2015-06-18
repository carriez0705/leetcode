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
    int height(TreeNode *node){
        if(!node) return -1;
        int count = 0;
        while(node->left){
            count += 1;
            node = node->left;
        }
        return count;
    }
    int count(TreeNode *node){
        if(!node) return 0;
        int h_left = height(node->left);
        int h_right = height(node->right);
        if(h_left==h_right){
            return pow(2,h_left+1)+count(node->right);
        }
        else{
            return count(node->left) + pow(2,h_right+1);
        }
    }
    int countNodes(TreeNode* root) {
        if(!root) return 0;
        return count(root);
    }
};
