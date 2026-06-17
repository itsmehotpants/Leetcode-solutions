class Solution {
public:
    int dp[13][10001];

    int solve(int i, vector<int>& coins, int amt) {

        if(amt == 0) return 0;

        if(i == coins.size())
            return 1e9;

        if(dp[i][amt] != -1)
            return dp[i][amt];

        int notTake =solve(i+1, coins, amt);

        int take = 1e9;

        if(coins[i] <= amt)
        {
         take =  1 + solve(i,coins,amt-coins[i]);
        }

        return dp[i][amt] =
               min(take, notTake);
    }

    int coinChange(vector<int>& coins, int amount) {

        memset(dp, -1, sizeof(dp));

        int ans = solve(0, coins, amount);

        return ans >= 1e9 ? -1 : ans;
    }
};