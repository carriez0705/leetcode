struct TNode{
    int val;
    int cnt;
    int dup;
    TNode *left, *right;
    TNode(int v ,int c=0, int d=1):val(v),cnt(c), dup(d), left(NULL), right(NULL){}
};
class Solution {
    int insert(TNode *root, TNode *node, int lcnt){
        if(root->val == node->val){
            delete node;
            root->dup += 1;
            return lcnt + root->cnt;
        }
        else if(root->val > node->val){
            root->cnt += 1;
            if(!root->left){
                root->left = node;
                return lcnt;
            }
            return insert(root->left, node, lcnt);
        }
        else{
            if(!root->right){
                root->right = node;
                return lcnt+root->dup+root->cnt;
            }
            return insert(root->right, node, lcnt + root->dup + root->cnt);
        }
    }
    void deleteNode(TNode *node){
        if(node->left)
            deleteNode(node->left);
        if(node->right)
            deleteNode(node->right);
        delete node;
    }
public:
    vector<int> countSmaller(vector<int>& nums) {
        vector<int> ans;
        if(!nums.size()) return ans;
        TNode *root = new TNode(nums[nums.size()-1]);
        ans.resize(nums.size());
        ans[nums.size()-1] = 0;
        for(int i = nums.size()-2; i>=0; i--){
            TNode *n = new TNode(nums[i]);
            ans[i] = insert(root, n, 0);
        }
        deleteNode(root);
        return ans;
    }
};
