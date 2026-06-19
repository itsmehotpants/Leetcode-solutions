class Solution {
public:

int n;
int solve(int  i, int buy,vector<int>& a,vector<vector<int>>&dp){
    if(i>=n) return 0;
    if(dp[i][buy]!=-1) return dp[i][buy];

    if(buy){
        return dp[i][buy] = max(-a[i]+solve(i+1,0,a,dp),solve(i+1,1,a,dp));
    }
    //sell
    return dp[i][buy]=max(a[i]+solve(i+2,1,a,dp),solve(i+1,0,a,dp));

}

    int maxProfit(vector<int>& a) {
         n  =a.size();
        vector<vector<int>>dp(n,vector<int>(2,-1));
        return solve(0,1,a,dp);
    }
};