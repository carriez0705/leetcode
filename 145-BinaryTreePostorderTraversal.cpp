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
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ans;
        if(!root) return ans;
        stack<TreeNode*> sta;
        sta.push(root);
        while(!sta.empty()){
            TreeNode *node = sta.top();
            if(node->right){
                sta.push(node->right);
            }
            if(node->left){
                sta.push(node->left);
            }
            node = sta.top();
            if(!node->left && !node->right){
                sta.pop();
                ans.push_back(node->val);
                while(!sta.empty() && ((sta.top()->left==node &&sta.top()->right==NULL) || sta.top()->right==node)){
                    node = sta.top();
                    sta.pop();
                    ans.push_back(node->val);
                }
            }
        }
        return ans;
    }
};
//-2 extra space 
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
    void stackpush(stack<TreeNode*> &nodstack, map<TreeNode*,int> &color, TreeNode* &node){
        nodstack.push(node);
        color[node] = 0;
    }
    vector<int> postorderTraversal(TreeNode* root) {
        stack<TreeNode*> nodstack;
        map<TreeNode*, int> color;
        vector<int> postorder;
        if(root) stackpush(nodstack, color, root);
        while(!nodstack.empty()){
            TreeNode *node = nodstack.top();
            if(!color[node]){
                if(node->right) stackpush(nodstack, color, node->right);
                if(node->left) stackpush(nodstack, color, node->left);
                color[node] = 1;
            }
            else{
                postorder.push_back(node->val);
                nodstack.pop();
            }
        }
        return postorder;
    }
};
