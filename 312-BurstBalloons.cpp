class Solution {
public:
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        if(!n) return 0;
        nums.insert(nums.begin(), 1);
        nums.push_back(1);
        vector<vector<int> > coins(n+2, vector<int>(n+2, 0));
        for(int len = 1; len<=n; len++){
            for(int i = 1; i<=n-len+1; i++){
                int end = i+len-1;
                for(int last = i;last<=end; last++){
                    int cur = coins[i][last-1]+coins[last+1][end];
                    cur += nums[i-1]*nums[last]*nums[end+1];
                    coins[i][end] = max(coins[i][end], cur);
                }
            }
        }
        return coins[1][n];
    }
};
