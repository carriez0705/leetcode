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
        TreeLinkNode *top = root;
        TreeLinkNode *leftest = NULL;
        while(top){
            leftest = top->left;
            while(top->next){
                if(top->left) top->left->next = top->right;
                if(top->right) top->right->next = top->next->left;
                top = top->next;
            }
            if(top->left)
                top->left->next = top->right;
            top = leftest;
        }
    }
};
