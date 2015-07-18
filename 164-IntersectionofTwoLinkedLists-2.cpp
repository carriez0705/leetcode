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
        if(!headA||!headB) return NULL;
        ListNode *ptr1=headA, *ptr2=headB, *tailA=NULL, *tailB=NULL;
        while(ptr1!=ptr2){
            if(ptr1->next)  ptr1 = ptr1->next;
            else{
                tailA = ptr1;
                ptr1 = headB;
            }
            if(ptr2->next) ptr2 = ptr2->next;
            else{
                tailB = ptr2;
                ptr2 = headA;
            }
            if(tailA && tailB && tailA!=tailB) return NULL;
        }
        return ptr1;
    }
};
