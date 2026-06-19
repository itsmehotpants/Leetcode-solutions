class Solution {
public:

int n;
int solve(int  i, int buy, int cap,vector<int>& a,vector<vector<vector<int>>>&dp){
    if(i>=n||cap==0) return 0;
    if(dp[i][buy][cap]!=-1) return dp[i][buy][cap];

    if(buy){
        return dp[i][buy][cap] = max(-a[i]+solve(i+1,0,cap,a,dp),solve(i+1,1,cap,a,dp));
    }
    //sell
    return dp[i][buy][cap]=max(a[i]+solve(i+1,1,cap-1,a,dp),solve(i+1,0,cap,a,dp));

}

    int maxProfit(vector<int>& a) {
         n  =a.size();
        vector<vector<vector<int>>>dp(n+1,vector<vector<int>>(2,vector<int>(3,-1)));
        return solve(0,1,2,a,dp);
    }
};