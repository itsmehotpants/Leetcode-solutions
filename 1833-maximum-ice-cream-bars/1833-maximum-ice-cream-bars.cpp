class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        sort(begin(costs), end(costs));
        
        int ans = 0;
        
        for(int &cost : costs) {
            if(cost > coins)
                return ans;
            else {
                ans++;
                coins -= cost;
            }
        }
        
        return ans;
    }
};