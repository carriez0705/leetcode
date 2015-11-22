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
    ListNode* partition(ListNode* head, int x) {
        ListNode *newhead = new ListNode(-1);
        newhead->next = head;
        ListNode *stail = newhead;
        ListNode *ltail = NULL;
        ListNode *node = newhead;
        while(node && node->next){
            ListNode *begin = node->next;
            while(node->next && node->next->val<x)
                node = node->next;
            ListNode *next = node->next;
            ListNode *n = stail->next;
            if(n!=begin){
                stail->next = begin;
                node->next = n;
            }
            stail = node;
            if(ltail){
                ltail->next = next;
                node = ltail;
            }
            while(node->next && node->next->val>=x){
                node = node->next;
            }
            ltail = node;
        }
        head = newhead->next;
        delete newhead;
        return head;
    }
};
