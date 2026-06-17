class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>>dp(n+1,vector<int>(amount+1,-1));
        return solve(coins, coins.size(), amount,dp);
    }

    int solve(vector<int>& coins, int idx, int amt, vector<vector<int>>&dp) {
        if (amt == 0) return 1;
        if (idx == 0) return 0;
        if(dp[idx][amt]!=-1) return dp[idx][amt];
        int skip = solve(coins, idx - 1, amt,dp);

        int take = 0;
        if (coins[idx - 1] <= amt)
            take = solve(coins, idx, amt - coins[idx - 1],dp);

        return dp[idx][amt]= skip + take;
    }
};