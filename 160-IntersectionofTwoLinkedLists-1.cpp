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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int m = 1, n = 1;
        if(!headA||!headB) return NULL;
        ListNode * ptr1=headA, *ptr2=headB;
        while(ptr1->next){
            m++;
            ptr1 = ptr1->next;
        }
        while(ptr2->next){
            n++;
            ptr2 = ptr2->next;
        }
        if(ptr1!=ptr2) return NULL;
        ptr1 = headA;
        ptr2 = headB;
        if(m>n){
            int r = m-n, i = 0;
            while(i<r){
               ptr1 = ptr1->next; 
               i++;
            }
        }
        else{
            int r = n-m, i = 0;
            while(i<r){
                ptr2= ptr2->next;
                i++;
            }
        }
        while(ptr1!=ptr2){
            ptr1 = ptr1->next;
            ptr2 = ptr2->next;
        }
        return ptr1;
    }
};
