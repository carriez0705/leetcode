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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(!n) return head;
        ListNode* fast = head;
        ListNode* slow = head;
        int count = 0;
        while(count<n && fast){
            count++;
            fast = fast->next;
        }
        if(!fast){
            //return count==n?head->next:head;
            if(count==n){
                ListNode* next_ = head->next;
                delete head;
                return next_;
            }
            else
                return head;
        }
            
        while(fast->next){
            slow = slow->next;
            fast = fast->next;
        }
        ListNode* next_= slow->next;
        slow->next = slow->next->next;
        delete next_;
        return head;
    }
};
