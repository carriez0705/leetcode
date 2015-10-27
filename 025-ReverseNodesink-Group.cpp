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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(k<=1) return head;
        ListNode *slow = head;
        ListNode *next_ = NULL;
        ListNode *pre = NULL;
        ListNode *fast = NULL;
        while(slow){
            int count = 0;
            next_ = slow;
            while(count<k-1){
                count++;
                next_ = next_->next;
                if(!next_) return head;
            }
            if(!pre) head = next_;
            else pre->next = next_;
            next_ = next_->next;
            
            count = 0;
            ListNode *curhead = slow;
            fast = slow->next;
            while(count<k-1){
                ListNode *fast_ = fast->next;
                fast->next = slow;
                slow = fast;
                fast = fast_;
                count++;
            }
            curhead->next = next_;
            slow = next_;
            pre = curhead;
        }
        return head;
    }
};
