/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
    void reverse(ListNode *&head){
        ListNode *pre = head;
        ListNode *node = head->next;
        pre->next = NULL;
        while(node){
            ListNode *next_ = node->next;
            node->next = pre;
            pre = node;
            node = next_;
        }
        head = pre;
    }
    void concatenate(ListNode *l1, ListNode *&pre, int &plus){
        while(l1&&plus){
            int v = l1->val + plus;
            if(v>=10){
                v = v-10;
                plus = 1;
            }
            else{
                plus = 0;
            }
            ListNode *newnode = new ListNode(v);
            pre->next = newnode;
            pre = newnode;
            l1 = l1->next;
        }
        if(plus){
            ListNode *newnode = new ListNode(plus);
            pre->next = newnode;
            pre = newnode;
        }
        pre->next = l1;
        
    }
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if(!l1) return l2;
        if(!l2) return l1;
        //reverse(l1);
        //reverse(l2);
        int plus = 0;
        ListNode *head = NULL;
        ListNode *pre = NULL;
        while(l1&&l2){
            int v = l1->val + l2->val + plus;
            if(v>=10){
                v = v-10;
                plus = 1;
            }
            else
                plus = 0;
            ListNode *newnode = new ListNode(v);
            if(!head)
                head = newnode;
            else
                pre->next = newnode;
            pre = newnode;
            l1 = l1->next;
            l2= l2->next;
        }
        if(!l1 && !l2 && plus){
            ListNode *newnode = new ListNode(plus);
            pre->next = newnode;
        }
        if(l1)
            concatenate(l1,pre,plus);
        
        if(l2)
            concatenate(l2,pre,plus);
        //reverse(head);
        return head;
        
    }
};
