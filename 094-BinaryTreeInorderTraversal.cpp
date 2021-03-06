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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        stack<TreeNode*> nodestack;
        if(root)
            nodestack.push(root);
        TreeNode *node = root;
        while(!nodestack.empty()){
            while(node && node->left){
                nodestack.push(node->left);
                node = node->left;
            }
            if(!nodestack.empty()){
                node = nodestack.top();
                ans.push_back(node->val);
                nodestack.pop();
                node = node->right;
                if(node) nodestack.push(node);
            }
        }
        return ans;
    }
};

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
    vector<int> inorderTraversal(TreeNode* root) {
        stack<TreeNode*> nodstack;
        //why hash_map could not be used??
        map<TreeNode*, int> color;
        vector<int> inorder;
        if(root){
            nodstack.push(root);
            color[root] = 0;
        }
        while(!nodstack.empty()){
            TreeNode *node = nodstack.top();
            if(!color[node]){
                if(node->left){ 
                    nodstack.push(node->left);
                    color[node->left] = 0;
                }
                color[node] = 1;
            }
            else{
                inorder.push_back(node->val);
                nodstack.pop();
                if(node->right){
                    nodstack.push(node->right);
                    color[node->right] = 0;
                }
            }
        }
        return inorder;
    }
};
