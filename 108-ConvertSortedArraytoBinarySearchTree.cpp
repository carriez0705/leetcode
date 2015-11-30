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
    TreeNode* build(vector<int> &nums, int begin, int end){
        if(begin>end) return NULL;
        if(begin==end) return new TreeNode(nums[begin]);
        int mid = (begin+end)>>1;
        TreeNode *node = new TreeNode(nums[mid]);
        node->left = build(nums, begin, mid-1);
        node->right = build(nums, mid+1, end);
        return node;
    }
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return build(nums, 0, nums.size()-1);
    }
};
