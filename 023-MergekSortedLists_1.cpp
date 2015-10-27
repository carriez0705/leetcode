//data structure- heap
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
struct comNode{
	ListNode *node;
	int id;
	comNode(ListNode* n, int index):node(n), id(index){}
};
bool comp(comNode *com1, comNode *com2){
	return com1->node->val > com2->node->val;
    }
class Solution {
    
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
	int n = lists.size();
	ListNode *head = NULL;
	if(!n)  return head;
	if(n==1 ) return lists[0];
	vector<comNode*> comheap;
	int count = n;
        for(int i= 0; i< n; i++){
		if(lists[i]){
			comNode* com = new comNode(lists[i], i);
			comheap.push_back(com);
			lists[i] = lists[i]->next;
		}
		else
			count--;
	}
	if(!count) return head;
	make_heap(comheap.begin(), comheap.end(), comp);
	ListNode *pre = NULL;
        int concatenate = -1;
	while(comheap.size()){
		comNode *min_ = comheap.front();
		pop_heap(comheap.begin(), comheap.end(), comp);
		comheap.pop_back();
		if(!pre) head = min_->node;
		else pre->next = min_->node;
		pre = min_->node;
		int index = min_->id;
		if(count>1){
		    if(lists[index]){
			comNode *com = new comNode(lists[index], index);
			comheap.push_back(com);
			lists[index] = lists[index]->next;
			push_heap(comheap.begin(), comheap.end(), comp);
		    }
		    else
			count--;
		}
		else if (count==1){
			concatenate = index;
		}
	}
	//if(concatenate!=-1)    
	    pre->next = lists[concatenate];
	return head;
    }
};
