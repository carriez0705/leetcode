/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:
    void connect(TreeLinkNode *root) {
        if(!root) return;
        TreeLinkNode *top = root;
        TreeLinkNode *leftest = top;
        TreeLinkNode *pre = NULL;
        while(leftest){
            top = leftest;
            leftest = NULL;
            while(top){
                if(top->left){
                    if(!leftest) leftest = top->left;
                    if(pre) pre->next = top->left;
                    pre = top->left;
                }
                if(top->right){
                    if(!leftest) leftest = top->right;
                    if(pre) pre->next = top->right;
                    pre = top->right;
                }
                top = top->next;
            }
            pre = NULL;
        }
    }
};
