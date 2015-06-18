struct node{
    int val ;
    int pos ;
};
class Solution {
public:
    void merge(vector<node> &nums, int left, int mid, int right){
        vector<node> back;
        for(int i = left; i<=mid; i++){
            back.push_back(nums[i]);
        }
        int i = 0, j = mid+1;
        int k = left;
        while(i<back.size()){
            if(j==right+1 || back[i].val<=nums[j].val){
                nums[k++] = back[i++];
            }
            else
                nums[k++] = nums[j++];
        }
    }
    void mergesort(vector<node> &nums, int left, int right){
        if(left>=right)
            return;
        int mid = (right+left)>>1;
        mergesort(nums,left,mid);
        mergesort(nums,mid+1,right);
        merge(nums, left, mid, right);
    }
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        bool exist = false;
        int n = nums.size();
        vector<node> nodvec;
        for(int i = 0; i<n; i++){
            struct node nod = {nums[i], i};
            nodvec.push_back(nod);
        }
        mergesort(nodvec, 0, n-1);
        for(int i = 1; i<n; i++){
            if(nodvec[i].val==nodvec[i-1].val){
                if(nodvec[i].pos-nodvec[i-1].pos<=k){
                    exist = true;
                    break;
                }
            }
        }
        return exist;
    }
};
