class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        if(!nums.size()) return ;
        k %= nums.size();
        int root = 0, i = 0;
        int n = nums.size();
        int temp = nums[0];
        while(n){
            int pos = (i+k)%nums.size();
            int t  = nums[pos];
            nums[pos] = temp;
            temp = t;
            i = pos;
            if(i==root){
                i += 1;
                root = i;
                temp = nums[i];
            }
            n--;
        }
    }
};
