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
    void deleteNode(ListNode* node) {
        while(node && node->next){
            node->val = node->next->val;
            if(!node->next->next){
                ListNode *temp =node->next;
                delete temp;
                node->next = NULL;
            }
            node = node->next;
        }
    }
};
