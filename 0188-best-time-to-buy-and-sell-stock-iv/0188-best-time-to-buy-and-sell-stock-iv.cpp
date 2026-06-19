class Solution {
public:

// int n;
// int solve(int  i, int buy, int cap,vector<int>& a,vector<vector<vector<int>>>&dp){
//     if(i>=n||cap==0) return 0;
//     if(curr[buy][cap]!=-1) return curr[buy][cap];

//     if(buy){
//         return curr[buy][cap] = max(-a[i]+solve(i+1,0,cap,a,dp),solve(i+1,1,cap,a,dp));
//     }
//     //sell
//     return curr[buy][cap]=max(a[i]+solve(i+1,1,cap-1,a,dp),solve(i+1,0,cap,a,dp));

// }

    int maxProfit(int k ,vector<int>& a) {
          int  n  =a.size();
        // vector<vector<vector<int>>>dp(n+1,vector<vector<int>>(2,vector<int>(k+1,0)));
        // return solve(0,0,2,a);
        vector<vector<int>>curr(2,vector<int>(k+1,0));
        vector<vector<int>>after(2,vector<int>(k+1,0));
  
        for(int  i=n-1;i>=0;i--){
            for(int buy =0;buy<=1;buy++){
                for(int cap =1;cap<=k;cap++){
                     if(buy==1){
         curr[buy][cap] = max(-a[i]+after[0][cap],after[1][cap]);
    }
    //sell
    else
     curr[buy][cap]=max(a[i]+after[1][cap-1],after[0][cap]);
                }
            }
            after= curr;
        }
        return after[1][k];
    }
};