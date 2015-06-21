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
    int findpos(int pivot, vector<int> &inorder, int left, int right){
        for(int i = left; i<=right; i++)
            if(pivot == inorder[i])
                return i;
        return -1;
    }
    int construct(int &i, int left, int right, vector<int> &preorder, vector<int> &inorder, vector<TreeNode*> &treevec){
        int node = i;
        int pos = findpos(preorder[i], inorder, left, right);
        if(pos!=left){
            i += 1;
            treevec[node]->left = treevec[construct(i,left, pos-1, preorder, inorder, treevec)];
        }
        if(pos!=right){
            i += 1;
            treevec[node]->right = treevec[construct(i, pos+1, right, preorder, inorder, treevec)];
        }
        return node;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if(!preorder.size()) return NULL;
        vector<TreeNode*> treevec(preorder.size());
        for(int i = 0; i<preorder.size(); i++){
            treevec[i] = new TreeNode(preorder[i]);
        }
        int i = 0;
        TreeNode* root = treevec[construct(i, 0, preorder.size()-1, preorder, inorder, treevec)];
        return root;
    }
};
