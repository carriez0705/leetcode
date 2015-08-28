class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size()<2) return 0;
        vector<int> profit(prices.size()+1,0);
        int max_ = prices[prices.size()-1];
        int p = INT_MIN;
        for(int i = prices.size()-1; i>=0; i--){
            p = max(p, max_-prices[i]);
            profit[i]=p;
            max_= max(prices[i], max_);
        }
        int min_= prices[0];
        int result = profit[0];
        p = INT_MIN;
        for(int i = 0; i<prices.size(); i++){
            p = max(p, prices[i]-min_);
            result = max(result, p+profit[i+1]);
            min_ = min(min_, prices[i]);
        }
        return result;
        
    }
};
