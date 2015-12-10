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
    ListNode* insertionSortList(ListNode* head) {
        if(!head) return head;
        ListNode *newhead = new ListNode(INT_MIN);
        newhead->next = head;
        ListNode *point = head->next;
        ListNode *iter = head, *pre = head;
        while(point){
            ListNode *previous = newhead;
            iter = previous->next;
            while(iter->val<=point->val && iter!=point){
                previous = iter;
                iter = iter->next;
            }
            ListNode *n = point->next;
            if(iter!=point){
                previous->next = point;
                point->next = iter;
                pre->next = n;
            }
            else
                pre = point;
            point = n;
            
        }
        head = newhead->next;
        delete newhead;
        return head;
    }
};
