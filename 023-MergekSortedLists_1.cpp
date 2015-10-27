//data structure- heap
//O(nlgk)
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
bool comp(ListNode *com1, ListNode *com2){
	return com1->val > com2->val;
    }
class Solution {
    
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
	int n = lists.size();
	ListNode *head = NULL;
	if(!n)  return head;
	if(n==1 ) return lists[0];
	vector<ListNode*> comheap;
	int count = n;
        for(int i= 0; i< n; i++){
		if(lists[i]){
			comheap.push_back(lists[i]);
		}
		else
			count--;
	}
	if(!count) return head;
	make_heap(comheap.begin(), comheap.end(), comp);
	ListNode *pre = NULL;
        ListNode *concatenate = NULL;
	while(comheap.size()){
		ListNode *min_ = comheap.front();
		pop_heap(comheap.begin(), comheap.end(), comp);
		comheap.pop_back();
		if(!pre) head = min_;
		else pre->next = min_;
		pre = min_;
		if(count>1){
		    if(min_->next){
			comheap.push_back(min_->next);
			push_heap(comheap.begin(), comheap.end(), comp);
		    }
		    else
			count--;
		}
		else if (count==1){
			concatenate = min_->next;
		}
	}
	pre->next = concatenate;
	return head;
    }
};
