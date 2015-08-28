class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        if(prices.size()<2) return 0;
        int n = prices.size();
        if(k>=n/2){
            int result = 0;
            for(int i = 0; i<n-1; i++){
                int diff = prices[i+1]-prices[i];
                result = max(result, result+diff);
            }
            return result;
        }
        vector<vector<int> > f(2, vector<int>(k+1,0));
        vector<vector<int> > g(2, vector<int>(k+1, 0));
        for(int j= 0; j<=k; j++){
            f[0][j] = 0;
            g[0][j] = 0;
        }
        for(int i = 0; i<n-1; i++){
            int diff = prices[i+1]-prices[i];
            f[1][0] = 0;
            g[1][0] = 0;
            for(int j = 1; j<=k; j++){
                f[1][j] = max(f[0][j],g[0][j]);
                g[1][j] = max(max(f[0][j-1]+diff, g[0][j]+diff), g[1][j-1]);
            }
            for(int j = 0; j<=k; j++){
                f[0][j] = f[1][j];
                g[0][j] = g[1][j];
            }
        }
        return max(f[0][k], g[0][k]);
    }
};
