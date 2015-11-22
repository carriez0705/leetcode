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
        ListNode *newhead = new ListNode(-1);
        newhead->next = head;
        ListNode *iter = newhead;
        ListNode *node = head;
        
        while(node){
            int count = 1;
            while(node->next && node->next->val == node->val){
                node = node->next;
                count++;
            }
            if(count==1){
                iter = iter->next;
                iter->val = node->val;
            }
            node = node->next;
        }
        iter->next = NULL;
        head = newhead->next;
        delete newhead;
        return head;
    }
};
