/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
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
    TreeNode* build(ListNode* head, int count){
        if(count<=0) return NULL;
        if(count==1) return new TreeNode(head->val);
        ListNode *node = head;
        int mid = (count>>1)+1;
        int c = 1;
        while(c<mid){
            node = node->next;
            c++;
        }
        TreeNode* root = new TreeNode(node->val);
        root->left = build(head, mid-1);
        root->right = build(node->next, count-mid);
        return root;
    }
public:
    TreeNode* sortedListToBST(ListNode* head) {
        int count = 0;
        ListNode *node = head;
        while(node){
            count++;
            node = node->next;
        }
        return build(head, count);
    }
};
