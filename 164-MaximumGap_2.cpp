class Solution {
public:
    int maximumGap(vector<int>& nums) {
        if(nums.size()<2) return 0;
        int smallest = nums[0], largest = nums[0];
        for(int i = 0; i<nums.size(); i++){
            smallest = min(smallest, nums[i]);
            largest = max(largest, nums[i]);
        }
        float bin = (largest-smallest)/(float)(nums.size()-1);
        int binsize = (largest-smallest)/bin;
        vector<pair<int, int> > vec(binsize+1, pair<int, int>(INT_MAX, INT_MIN));
        for(int i = 0; i<nums.size(); i++){
            int b = (nums[i]-smallest)/bin;
            vec[b].first = min(vec[b].first, nums[i]);
            vec[b].second = max(vec[b].second, nums[i]);
        }
        int maxlen = 0;
        for(int i = 1; i<vec.size(); i++){
            if(vec[i].first==INT_MAX && vec[i].second==INT_MIN){
                vec[i].first = vec[i-1].first;
                vec[i].second = vec[i-1].second;
            }
            else{
                if(vec[i-1].second>=0)
                    maxlen = max(maxlen, vec[i].first-vec[i-1].second);
            }
        }
        return maxlen;
    }
};
