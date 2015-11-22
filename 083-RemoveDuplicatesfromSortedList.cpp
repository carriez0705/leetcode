/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode *node = head;
        while(node){
            ListNode *begin = node;
            while(node->next && node->next->val == node->val)
                node= node->next;
            begin->next = node->next;
            node = node->next;
        }
        return head;
    }
};
