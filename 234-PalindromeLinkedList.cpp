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
    bool isPalindrome(ListNode* head) {
        ListNode *node = head;
        int count = 0;
        while(node){
            count += 1;
            node = node->next;
        }
        if(!count) return true;
        int i = 1;
        int mid = (count+1)/2;
        node = head;
        while(i<mid){
            i += 1;
            node = node->next;
        }
        ListNode *prev = node;
        node = node->next;
        prev->next = NULL;
        while(node){
            ListNode *temp = node->next;
            node->next = prev;
            prev = node;
            node = temp;
        }
        ListNode *head2 = prev;
        while(head&&head2){
            if(head->val!=head2->val)
                return false;
            head = head->next;
            head2 = head2->next;
        }
        return true;
    }
};
