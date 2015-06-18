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
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        bool exist = false;
        int n = nums.size();
        vector<node> nodvec;
        for(int i = 0; i<n; i++){
            struct node nod = {nums[i], i};
            nodvec.push_back(nod);
        }
        mergesort(nodvec, 0, n-1);
        for(int i = 1; i<n; i++){
            for(int j = i-1; j>=0; j-- ){
                long long diff = (long long)nodvec[i].val-(long long)nodvec[j].val;
                if(diff<=(long long)t){
                    if(abs(nodvec[i].pos-nodvec[j].pos)<=k){
                        exist = true;
                        return exist;
                    }
                }
                else
                    break;
            }
            
        }
        return exist;
    }
};
