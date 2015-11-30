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
    int find(vector<int> &inorder, int b1, int e1, int val){
        for(int i = b1; i<=e1; i++){
            if(inorder[i]==val)
                return i;
        }
        return -1;
    }
    TreeNode* build(vector<int> &inorder, int b1, int e1, vector<int> &postorder, int b2, int e2){
        if(b1>e1) return NULL;
        if(b1==e1) return new TreeNode(inorder[b1]);
        int pos = find(inorder, b1, e1, postorder[e2]);
        int rightlen = e1-pos;
        int leftlen = pos-b1;
        TreeNode *node = new TreeNode(postorder[e2]);
        node->left = build(inorder, b1, pos-1, postorder, b2, b2+leftlen-1);
        node->right = build(inorder, pos+1, e1, postorder, e2-rightlen, e2-1 );
        return node;
    }
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if(inorder.size()!=postorder.size()) return NULL;
        return build(inorder, 0, inorder.size()-1, postorder, 0, postorder.size()-1);
    }
};
