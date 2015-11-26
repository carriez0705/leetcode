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
    void dfs(int begin, int end, vector<TreeNode*> &nodevec){
        if(begin>end){
            nodevec.push_back(NULL);
            return;
        }
        for(int i = begin; i<=end; i++){
            vector<TreeNode*> leftn;
            dfs(begin, i-1, leftn);
            vector<TreeNode*> rightn;
            dfs(i+1, end, rightn);
            for(int l = 0; l<leftn.size(); l++){
                for(int r = 0; r<rightn.size(); r++){
                    TreeNode *central = new TreeNode(i);
                    central->left = leftn[l];
                    central->right = rightn[r];
                    nodevec.push_back(central);
                }
            }
        }
    }
public:
    vector<TreeNode*> generateTrees(int n) {
        vector<TreeNode*> ans;
        if(!n) return ans;
        dfs(1,n, ans);
        return ans;
    }
};
