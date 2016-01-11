//segment tree
//ATTENTION: memery size 2*pow(2, ceil(log2(n)))-1
class SegmentTree{
    vector<int> segment;
    int num;
    void updatehelper(int st, int end, int id, int index){
        if(st<=id && end>=id){
            segment[index]++;
        }
        if(st==end || st>id || end<id) return;
        int mid = (st+end)>>1;
        updatehelper(st, mid, id, 2*index+1);
        updatehelper(mid+1, end, id, 2*index+2);
    }
    int queryhelper(int st, int end, int lower, int upper, int index){
        if(lower<=st && upper>=end)
            return segment[index];
        if(st>upper || end<lower)
            return 0;
        int mid = (st+end)>>1;
        int l = queryhelper(st, mid, lower, upper, 2*index+1);
        int r = queryhelper(mid+1, end, lower, upper, 2*index+2);
        return l+r;
    }
public:
    SegmentTree(int n):num(n){
        segment.clear();
        //memory size for segment tree: 2*pow(2, ceil(log2(n)))-1
        //n<pow(2,h)<2n -> h = ceil(logn)
        //full binery tree: n nodes with n-1 inner nodes
        //pow(2, h)+pow(2,h)-1;
        int h = (int)ceil(log2(n));
        int size = 2*pow(2, h)-1;
        segment.resize(size);
    }
    void update(int id){
        updatehelper(0, num-1, id, 0);
    }
    int query(int lower, int upper){
        return queryhelper(0, num-1, lower, upper,0);
    }
};
struct Node{
    int val, index;
    Node(int v, int i):val(v), index(i){}
};
bool cmp(Node &n1, Node &n2){
    if(n1.val!=n2.val)
        return n1.val<n2.val;
    return n1.index<n2.index;
}
class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) 
    {
        int n = nums.size();
        vector<int> ans(n, 0);
        if(!n) return ans;
        vector<Node> nodvec;
        for(int i = 0; i<nums.size(); i++){
            nodvec.push_back(Node(nums[i], i));
        }
        sort(nodvec.begin(), nodvec.end(), cmp);
        SegmentTree sg(n);
        for(int i = 0; i<n; i++){
            ans[nodvec[i].index] = sg.query(nodvec[i].index, n-1);
            sg.update(nodvec[i].index);
            //cout<<i<<endl;
        }
        return ans;
    }
};
 
