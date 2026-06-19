class Solution {
public:
int solve(int  i ,int buy,vector<int>&a,vector<vector<int>>&dp,int fee){
    if(i>=a.size()) return 0;
    if(dp[i][buy]!=-1) return dp[i][buy];
    if(buy){
        return dp[i][1] = max(-a[i]+solve(i+1,0,a,dp,fee),solve(i+1,1,a,dp,fee));
    }
    return dp[i][0] = max(a[i]-fee+solve(i+1,1,a,dp,fee),solve(i+1,0,a,dp,fee)); 
}
    int maxProfit(vector<int>& a, int fee) {
        int n =a.size();
        vector<vector<int>>dp(n+2,vector<int>(2,-1));
        for(int i = n-1;i>=0;i--){
             
         dp[i][1] = max(-a[i]+dp[i+1][0],dp[i+1][1]);
    
     dp[i][0] = max(a[i]-fee+dp[i+1][1],dp[i+1][0]); 
        }
        return dp[0][1]+1;
    }
};