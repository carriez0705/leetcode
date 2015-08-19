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
    ListNode* reverseList(ListNode* head) {
        if(!head||!head->next) return head;
        ListNode* node = head->next;
        head->next = NULL;
        ListNode *pre=head, *nxt = NULL;
        while(node){
            nxt = node->next;
            node->next = pre;
            pre = node;
            node = nxt;
            if(!node) return pre;
        }
        return head;
    }
};
