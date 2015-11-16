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
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head || !(head->next) ) return head;
        int count = 0;
        ListNode *node = head;
        while(node){
            count++;
            node = node->next;
        }
        k = k%count;
        if(k==0) return head;
        ListNode *fast = head;
        node = head;
        count = 0;
        while(count<k){
            fast = fast->next;
            count++;
        }
        while(fast->next){
            node = node->next;
            fast = fast->next;
        }
        ListNode *newhead = node->next;
        fast->next = head;
        node->next = NULL;
        return newhead;
    }
};
