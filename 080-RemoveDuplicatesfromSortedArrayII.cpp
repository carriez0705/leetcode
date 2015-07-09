class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i = -1, j= 0;
        while(j<nums.size()){
            int count = 1;
            while(j<nums.size()-1 && nums[j+1]==nums[j]){
                count++;
                j++;
            }
            int c = min(count, 2);
            while(c){
                nums[++i] = nums[j];
                c--;
            }
            j++;
        }
        return i+1;
    }
};
