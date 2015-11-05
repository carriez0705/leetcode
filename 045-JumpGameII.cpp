class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        if(n<=1) return 0;
        int pre = -1;
        int farest = 0;
        int i = 0;
        //bool reachable = false;
        int step = 0;
        while(i<n){
            step+=1;
            int onestep = farest;
            for(i = pre+1; i<=farest; i++){
                int curfar = i+nums[i];
                if(curfar>=n-1)
                    return step;
                onestep = max(onestep, curfar);
            }
            pre = farest;
            farest = onestep;
        }
        return INT_MAX;
    }
};
