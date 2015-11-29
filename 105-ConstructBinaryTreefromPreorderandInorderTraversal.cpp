//-1
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
    int find(int val, vector<int> &inorder, int begin, int end){
        for(int i = begin; i<=end; i++){
            if(inorder[i]==val)
                return i;
        }
        return -1;
    }
    TreeNode* build(vector<int> &preorder, int b1, int e1, vector<int> &inorder, int b2, int e2){
        if(b2>e2) return NULL;
        if(b2==e2) return new TreeNode(inorder[b2]);
        TreeNode *root = new TreeNode(preorder[b1]);
        int pos = find(preorder[b1], inorder, b2, e2);
        int len1 = pos-b2;
        int len2 = e2-pos;
        root->left = build(preorder, b1+1, b1+len1, inorder, b2, pos-1);
        root->right = build(preorder, b1+len1+1, e1, inorder, pos+1, e2);
    }
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return build(preorder, 0, preorder.size()-1, inorder, 0, inorder.size()-1);
    }
};


//-2
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
