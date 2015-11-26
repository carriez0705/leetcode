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
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        if(m==n) return head;
        ListNode *newhead = new ListNode(-1);
        newhead->next = head;
        ListNode *node = newhead;
        int count = 0;
        while(count<m-1){
            node = node->next;
            count++;
        }
        ListNode *last = node;
        node = node->next;
        count++;
        ListNode *end = node;
        ListNode *pre = NULL;
        while(node && count<=n){
            ListNode *n = node->next;
            if(pre)
                node->next = pre;
            pre = node;
            node = n;
            count++;
        }
        last->next = pre;
        end->next = node;
        head = newhead->next;
        delete newhead;
        return head;
    }
};
