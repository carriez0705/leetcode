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
    vector<int> closestKValues(TreeNode* root, double target, int k) {
        stack<TreeNode*> pred, succ;
        stack_init(root, target, pred, succ);
        vector<int> ans;
        int count = 0;
        while(count<k){
            if(succ.empty() || !pred.empty()&&(target-pred.top()->val < succ.top()->val-target)){
                ans.push_back(pred.top()->val);
                getPredecessor(pred);
            }
            else{
                ans.push_back(succ.top()->val);
                getSuccessor(succ);
            }
            count++;
        }
        return ans;
    }
    void stack_init(TreeNode *node, double target, stack<TreeNode*> &pred, stack<TreeNode*> &succ){
        while(node){
            if(target<=node->val){
                succ.push(node);
                node= node->left;
            }
            else{
                pred.push(node);
                node= node->right;
            }
        }
    }
    void getPredecessor(stack<TreeNode*> &pred){
        TreeNode *p = pred.top();
        pred.pop();
        if(p->left){
            pred.push(p->left);
            while(pred.top()->right) pred.push(pred.top()->right);
        }
    }
    void getSuccessor(stack<TreeNode*> &succ){
        TreeNode *s = succ.top();
        succ.pop();
        if(s->right){
            succ.push(s->right);
            while(succ.top()->left) succ.push(succ.top()->left);
        }
    }
};
