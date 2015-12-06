/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        if(!head) return NULL;
        unordered_map<RandomListNode*, RandomListNode*> copy;
        RandomListNode *node = head;
        RandomListNode *pre = NULL;
        while(node){
            RandomListNode *cp = new RandomListNode(node->label);
            copy[node] = cp;
            if(pre)
                pre->next = cp;
            pre = cp;
            node = node->next;
        }
        node = head;
        while(node){
            copy[node]->random = copy[node->random];
            node = node->next;
        }
        return copy[head];
    }
};
