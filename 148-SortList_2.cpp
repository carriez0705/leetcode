/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
    void partition(ListNode *head, ListNode * tail, ListNode *&firsth, ListNode *&first, ListNode *&secondh, ListNode *&second){
        if(head==tail) return;
        //randomize
        ListNode *node = head;
        int count = 1;
        while(node!=tail){
            node = node->next;
            count++;
        }
        int rnd = rand()%count;
        node = head;
        while(rnd){
            node = node->next;
            rnd--;
        }
        swap(node->val, tail->val);
        
        node = head;
        int pivot = tail->val;
        while(node!=tail){
            if(node->val<=pivot){
                if(!firsth){
                    firsth = node;
                }
                else{
                    first->next = node;
                }
                first = node;
            }
            else{
                if(!secondh){
                    secondh = node;
                }
                else{
                    second->next = node;
                }
                second = node;
            }
            node = node->next;
        }
        if(firsth){
            first->next = node;
        }
        if(secondh){
            node->next = secondh;
        }
    }
    void quicksort(ListNode *pre, ListNode *head, ListNode *tail, ListNode *after){
        if(head==tail) return;
        ListNode *firsth = NULL, *secondh = NULL, *first = NULL, *second = NULL;
        partition(head, tail,firsth, first, secondh, second);
        if(!firsth){
            pre->next = tail;
        }
        else{
            pre->next = firsth;
            quicksort(pre, firsth, first, tail);
        }
        if(!secondh){
            tail->next = after;
        }
        else{
            second->next = after;
            quicksort(tail, secondh, second, after);
        }
    }
public:
    ListNode* sortList(ListNode* head) {
        if(!head) return head;
        ListNode *newhead = new ListNode(-1);
        newhead->next = head;
        ListNode *node = head;
        while(node->next){
            node = node->next;
        }
        quicksort(newhead, head, node, NULL);
        head = newhead->next;
        delete newhead;
        return head;
    }
};
