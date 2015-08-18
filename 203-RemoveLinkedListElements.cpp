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
        ListNode* node = head, *newhead = NULL;
        while(node&&node->val==val){
            node= node->next;
        }
        newhead = node;
        while(node && node->next){
            while(node->next&&node->next->val==val){
                node->next = node->next->next;
            }
            node = node->next;
        }
        return newhead;
    }
};
