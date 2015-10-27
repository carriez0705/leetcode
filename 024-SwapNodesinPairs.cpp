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
    ListNode* swapPairs(ListNode* head) {
        ListNode *slow = head;
        ListNode *fast = NULL;
        if(head) fast = head->next;
        if(!slow || !fast) return head;
        head = fast;
        ListNode *pre = NULL;
        while(slow && fast){
            ListNode *slow_ = fast->next;
            ListNode *fast_ = fast->next?fast->next->next : NULL;
            if(pre) pre->next = fast;
            fast->next = slow;
            slow->next = slow_;
            pre = slow;
            slow = slow_;
            fast = fast_;
        }
        return head;
    }
};
