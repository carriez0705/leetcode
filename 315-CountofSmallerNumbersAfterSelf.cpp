class Solution {
    void merge(vector<int> &nums, int begin, int end, vector<int> &inverse, vector<int> &pos){
        if(begin==end){
            pos[begin] = begin;
            return;
        }
        int mid = (begin+end)>>1;
        merge(nums, begin, mid, inverse, pos);
        merge(nums, mid+1, end, inverse, pos);
        vector<int> backup1(nums.begin()+begin, nums.begin()+mid+1);
        vector<int> backup2(inverse.begin()+begin, inverse.begin()+mid+1);
        vector<int> backup3(pos.begin()+begin, pos.begin()+mid+1);
        int i = 0, j = mid+1;
        int n1 = mid-begin;
        int count2 = 0;
        while(i<=n1 && j<=end){
            if(backup1[i]<=nums[j]){
                nums[begin] = backup1[i];
                inverse[begin] = backup2[i]+count2;
                pos[begin] = backup3[i];
                i++;
            }
            else{
                nums[begin] = nums[j];
                inverse[begin] = inverse[j];
                pos[begin] = pos[j];
                j++;
                count2++;
            }
            begin++;
        }
        while(i<=n1){
            nums[begin] = backup1[i];
            inverse[begin] = backup2[i] + count2;
            pos[begin] = backup3[i];
            i++;
            begin++;
        }
    }
public:
    vector<int> countSmaller(vector<int>& nums) {
        if(!nums.size()) return nums;
        vector<int> inverse(nums.size(), 0);
        vector<int> pos(nums.size(), 0);
        if(nums.size()>1){
            merge(nums, 0, nums.size()-1, inverse, pos);
        }
        for(int i = 0; i<pos.size(); i++){
            nums[pos[i]] = inverse[i];
        }
        return nums;
    }
};
