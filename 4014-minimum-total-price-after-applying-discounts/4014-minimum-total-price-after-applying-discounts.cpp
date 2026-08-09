class Solution {
public:
    double minPrice(vector<int>& prices, vector<int>& discounts) {
        sort(prices.rbegin(), prices.rend());
        sort(discounts.rbegin(), discounts.rend());

        double ans = 0.0;
        int n = prices.size();
        int m = discounts.size();

        for (int i = 0; i < n; i++) {
            if (i < m) {
                ans += (double)prices[i] * (100.0 - discounts[i]) / 100.0;
            } else {
                ans += prices[i];
            }
        }
        
        return ans;
    }
};