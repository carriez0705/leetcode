class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int len = 0;
        map<int, int> numap;
        for(int i = 0; i<nums.size(); i++){
            if(numap.find(nums[i])!=numap.end()) continue;
            numap[nums[i]]= 1;
            if(numap.find(nums[i]+1)!=numap.end() && numap[nums[i]+1]>0){
                numap[nums[i]] += numap[nums[i]+1];
                int last = nums[i] + numap[nums[i]+1];
                numap.erase(nums[i]+1);
                numap[last] = -(last - nums[i]+1);
            }
            if(numap.find(nums[i]-1) != numap.end() && numap[nums[i]-1]<=1){
                int first = numap[nums[i]-1]==1? nums[i]-1 : nums[i]+numap[nums[i]-1];
                int last = nums[i]+numap[nums[i]]-1;
                int d = last -first +1;
                numap.erase(nums[i]-1);
                numap.erase(nums[i]);
                numap[first] = d;
                numap[last] = -d;
                len = max(len, d);
            }
            len = max(len, numap.find(nums[i])!=numap.end()?abs(numap[nums[i]]):0);
        }
        return len;
    }
};
