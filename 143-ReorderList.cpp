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
    void reorderList(ListNode* head) {
        if(!head) return;
        ListNode *fast=head, *slow = head;
        int count = 0;
        while(fast->next){
            slow = slow->next;
            fast = fast->next;
            count++;
            if(fast->next){
                fast = fast->next;
                count++;
            }
        }
        if(count<=1)
            return;
        ListNode *pre = slow;
        fast = slow->next;
        slow->next = NULL;
        while(fast){
            ListNode *n = fast->next;
            fast->next = pre;
            pre = fast;
            fast = n;
        }
        slow = head;
        fast = pre;
        while(fast->next && slow!=fast){
            ListNode *slown = slow->next;
            ListNode *fastn = fast->next;
            slow->next = fast;
            fast->next = slown;
            slow = slown;
            fast = fastn;
        }
        
    }
};
