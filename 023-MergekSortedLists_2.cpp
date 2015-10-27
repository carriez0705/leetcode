//divide and conquer
//T(n) = T(n/2) + nlgn
//but it's faster than method 1(heap) in online judge

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

class Solution {
    ListNode *mergeTwoLists(vector<ListNode *> &lists, int begin, int end){
	if(begin>end) return NULL;
	if(begin==end) return lists[begin];
	int mid = (begin+end)>>1;
	ListNode *left = mergeTwoLists(lists, begin, mid);
	ListNode *right = mergeTwoLists(lists, mid+1, end);
	ListNode *head = NULL;
	ListNode *pre = NULL;
	if(!left) return right;
	if(!right) return left;
	if(left->val < right->val){
		head = left;
		left = left->next;
	}
	else{
		head = right;
		right = right->next;
	}
	pre = head;
	while(left && right){
	    if(left->val<right->val){
		pre->next = left;
		left = left->next;
	    }
	    else{
		pre->next = right;
		right = right->next;
	    }
	    pre = pre->next;
	}
	if(left) pre->next = left;
	if(right) pre->next = right;
	return head;
    }
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
	int n = lists.size();
	return mergeTwoLists(lists, 0, n-1);
    }
};
