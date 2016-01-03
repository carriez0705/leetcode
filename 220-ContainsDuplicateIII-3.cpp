class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        //corner cases: k<=0, t<0, t=0
        if(k<=0 || t<0) return false;
        unordered_map<int, int> pos;
        for(int i = 0; i<nums.size(); i++){
            int j = i-k-1;
            if(j>=0) pos.erase(nums[j]/(t+1));
            int p = nums[i]/(t+1);
            if(check(pos, p, nums[i],t)||check(pos, p-1, nums[i],t)|| check(pos, p+1, nums[i],t))
                return true;
            pos[p] = nums[i];
        }
        return false;
    }
    bool check(unordered_map<int, int> &pos, int index, int num, int t){
        auto iter = pos.find(index);
        if(iter==pos.end()) return false;
        //corner cases
        long long n2 = iter->second;
        if(abs(n2-num)<=t) return true;
        return false;
    }
};
