class Solution {
    int mergesort(vector<long long> &sum, int st, int end, int lower, int upper){
        if(st==end)
            return sum[st]>=lower && sum[st]<=upper;
        if(st>end) return 0;
        int mid = (st+end)>>1;
        int left = mergesort(sum, st, mid, lower, upper);
        int right = mergesort(sum, mid+1, end, lower, upper);
        vector<long long> temp;
        int i = st, j = mid+1, k = mid+1, t = mid+1;
        int cross = 0;
        while(i<=mid){
            while(j<=end && sum[j]-sum[i]<(long long)lower)
                j++;
            while(k<=end && sum[k]-sum[i]<=(long long)upper)
                k++;
            int p = t;
            while(t<=end && sum[t]<sum[i])
                t++;
            cross += k-j;
            while(p<t){
                temp.push_back(sum[p]);
                p++;
            }
            temp.push_back(sum[i]);
            i++;
        }
        int p = 0;
        i = st;
        while(p<temp.size()){
            sum[i] = temp[p];
            p++;
            i++;
        }
        return left+right+cross;
    }
public:
    int countRangeSum(vector<int>& nums, int lower, int upper) {
        vector<long long> sum(nums.size(), 0);
        if(!nums.size()) return 0;
        sum[0] = (long long)nums[0];
        for(int i = 1; i<nums.size(); i++)
            sum[i] = sum[i-1]+nums[i];
        return mergesort(sum, 0, nums.size()-1, lower, upper);
    }
};
