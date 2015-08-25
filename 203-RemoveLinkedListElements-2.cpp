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
    ListNode* removeElements(ListNode* head, int val) {
        while(head&&head->val==val){
            ListNode *temp = head;
            head = head->next;
            delete temp;
        }
        if(!head) return head;
        ListNode *pre = head;
        ListNode *node = pre->next;
        while(node){
            while(node&&node->val==val){
                pre->next = node->next;
                delete node;
                node = pre->next;
            }
            pre = node;
            if(node) node = node->next;
        }
        return head;
    }
};
