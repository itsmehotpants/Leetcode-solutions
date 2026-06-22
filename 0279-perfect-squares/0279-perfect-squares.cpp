// class Solution {
// public:

// int dp[10001];
// int solve(int n){
//     if(n==0) return 0;
//     if(dp[n]!=-1) return dp[n];
//     int cnt=INT_MAX;


//     for(int i =1;i*i<=n;i++){
//         int res =1+ solve(n-i*i);
//         cnt= min(cnt,res);
//     }
//     return dp[n]=cnt;
// }
//     int numSquares(int n) {
//         memset(dp,-1,sizeof(dp));
//         return solve(n);
//     }
// };

class Solution {
public:
    int numSquares(int n) {
        vector<int> dp(n+1,INT_MAX);
        dp[0]=0;
        int cnt = 1;
        while(cnt*cnt <= n) {
        int sq = cnt*cnt;
        for(int i = sq; i < n+1; i++) {
            dp[i] = min(dp[i-sq] + 1,dp[i]);
        }
        cnt++;
    }
    return dp[n];
    }
};