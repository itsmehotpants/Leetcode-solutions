class Solution {
public:
    int maxConsistentColumns(vector<vector<int>>& g, int limit) {
       int m =g.size(),n=g[0].size();
        vector<int>dp(n,1);
        int ans=1;
        for(int i =0;i<n;i++){
            for(int j =0;j<i;j++){
                bool flag =true;
                for(int k =0;k<m&&flag;k++){
                    if(abs(g[k][i]-g[k][j])>limit) flag =false;
                }
                if(flag) dp[i] = max(dp[i],dp[j]+1);
            }
            ans =max(ans,dp[i]);
        }
        return ans;
    }
};