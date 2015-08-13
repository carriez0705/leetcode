class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size()<=1) return 0;
        int bot= INT_MAX;
        int peak = INT_MIN;
        if(prices[1]>=prices[0])
            bot = prices[0];
        int diff = 0;
        for(int i = 1; i<prices.size(); i++){
            if(i<prices.size()-1 && prices[i-1]>prices[i] &&prices[i]<=prices[i+1]){
                bot = prices[i];
            }
            else if((i==prices.size()-1&&prices[i]>bot) ||(prices[i-1]<=prices[i]&&prices[i]>prices[i+1])){
                peak = prices[i];
                diff += peak-bot;
                bot = INT_MAX;
            }
        }
        return diff;
    }
};
