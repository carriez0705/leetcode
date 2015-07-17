struct Node{
    int left, right, split;
    Node *lch, *rch;
    Node(int x, int y):left(x),right(y),split(x),lch(NULL), rch(NULL){}
};
class Solution {
public:
    void findmax(Node *ptr, int &gap){
        if(!ptr->lch && !ptr->rch){
            gap = max(gap, ptr->right-ptr->left);
            delete ptr;
            return;
        }
        if(ptr->lch)
            findmax(ptr->lch, gap);
        if(ptr->rch)
            findmax(ptr->rch, gap);
        delete ptr;
    }
    void insert(int x, Node *root){
        while(root->split!=root->left){
            if(x<=root->split)
                root = root->lch;
            else
                root = root->rch;
        }
        if(x==root->left || x ==root->right) return;
        root->split = x;
        root->lch = new Node(root->left, x);
        root->rch = new Node(x, root->right);
    }
    int maximumGap(vector<int>& nums) {
        if(nums.size()<2) return 0;
        int head = nums[0], tail = nums[1];
        for(int i = 0; i<nums.size(); i++){
            head = min(head, nums[i]);
            tail = max(tail, nums[i]);
        }
        Node *ptr = new Node(head, tail);
        for(int i = 0; i<nums.size();i++){
            insert(nums[i], ptr);
        }
        int gap = 0;
        findmax(ptr, gap);
        return gap;
    }
};
