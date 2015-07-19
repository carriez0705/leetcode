/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class BSTIterator {
    stack<TreeNode *> mystack;
    void inorder(TreeNode *node){
        mystack.push(node);
        if(node->left)
            inorder(node->left);
        
    }
    void restore(TreeNode *node){
        if(node->right)
            inorder(node->right);
    }
public:
    BSTIterator(TreeNode *root) {
        while(!mystack.empty()) mystack.pop();
        if(root) inorder(root);
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
        return !mystack.empty();
    }

    /** @return the next smallest number */
    int next() {
        TreeNode *ret = mystack.top();
        mystack.pop();
        restore(ret);
        return ret->val;
    }
};

/**
 * Your BSTIterator will be called like this:
 * BSTIterator i = BSTIterator(root);
 * while (i.hasNext()) cout << i.next();
 */
