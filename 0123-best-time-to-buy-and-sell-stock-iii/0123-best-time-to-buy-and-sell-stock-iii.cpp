class Solution {
public:
// vector<vector<vector<int>>>dp
// int n;
// int solve(int  i, int buy, in cap,vector<int>& a){
//     if(i>=n||cap==0) return 0;
//     if(dp[i][buy][cap]!=-1) return dp[i][buy][cap];

//     if(buy){
//         return dp[i][buy][cap] = max(-a[i]+solve(i+1,0,cap,a),solve(i+1,1,cap,a));
//     }
//     //sell
//     return dp[i][buy][cap]=max(a[i]+solve(i+1,1,cap-1,a),solve(i+1,0,cap,a));

// }

    int maxProfit(vector<int>& a) {
       int  n  =a.size();
        vector<vector<vector<int>>>dp(n+1,vector<vector<int>>(2,vector<int>(3,0)));
        // return solve(0,0,2,a);
        for(int  i=n-1;i>=0;i--){
            for(int buy =0;buy<=1;buy++){
                for(int cap =1;cap<=2;cap++){
                     if(buy==1){
         dp[i][buy][cap] = max(-a[i]+dp[i+1][0][cap],dp[i+1][1][cap]);
    }
    //sell
    else
     dp[i][buy][cap]=max(a[i]+dp[i+1][1][cap-1],dp[i+1][0][cap]);
                }
            }
        }
        return dp[0][1][2];
    }
};