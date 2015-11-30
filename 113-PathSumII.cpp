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
    void dfs(TreeNode *node, int sum, vector<vector<int> > &ans, vector<int> &vec){
        if(!node) return;
        if(!node->left && !node->right){
            if(node->val==sum){
                vec.push_back(node->val);
                ans.push_back(vec);
                vec.pop_back();
            }
            return;
        }
        
            vec.push_back(node->val);
            dfs(node->left, sum-node->val, ans, vec);
            dfs(node->right, sum-node->val, ans, vec);
            vec.pop_back();
        
    }
public:
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int> > ans;
        vector<int> vec;
        dfs(root, sum, ans, vec);
        return ans;
    }
};
