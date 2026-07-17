class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ans  =0;
        int buy=INT_MAX,sell=INT_MIN;
        for(int i = 0;i<prices.size();i++){
             buy = min(buy,prices[i]);
            sell = max(sell,prices[i]-buy);
        }
        return sell;
    }
};