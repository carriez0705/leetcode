/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
    ListNode* forward_one(ListNode* &ptr){
        if(ptr&&ptr->next)
            return ptr->next;
        return NULL;
    }
    ListNode* forward_two(ListNode* &ptr){
        if(ptr&&ptr->next&&ptr->next->next)
            return ptr->next->next;
        return NULL;
    }
public:
    ListNode *detectCycle(ListNode *head) {
        if(!head) return head;
        ListNode* slow = head;
        ListNode* fast = head;
        while(1){
            fast = forward_two(fast);
            slow = forward_one(slow);
            if(!fast)
                return fast;
            if(fast==slow){
                fast = head;
                while(fast!=slow){
                    fast = forward_one(fast);
                    slow = forward_one(slow);
                }
                return slow;
            }
        }
        return NULL;
    }
};
