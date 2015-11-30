//dfs
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
    int dfs(TreeNode *node){
        if(!node) return 0;
        int leftH = dfs(node->left);
        int rightH = dfs(node->right);
        if(leftH==0 && rightH==0)
            return 1;
        else if(!leftH || !rightH)
            return max(leftH, rightH)+1;
        else
            return min(leftH, rightH) + 1;
    }
public:
    int minDepth(TreeNode* root) {
        return dfs(root);
    }
};

//bfs
class Solution {
public:
    int minDepth(TreeNode* root) {
        queue<TreeNode*> que;
        map<TreeNode*, int> level;
        if(!root) return 0;
        que.push(root);
        level[root] = 1;
        while(!que.empty()){
            TreeNode *node = que.front();
            que.pop();
            if(!node->left && !node->right){
                return level[node];
            }
            if(node->left){
                que.push(node->left);
                level[node->left] = level[node] + 1;
            }
            if(node->right){
                que.push(node->right);
                level[node->right] = level[node] + 1;
            }
        }
        return -1;
    }
};
