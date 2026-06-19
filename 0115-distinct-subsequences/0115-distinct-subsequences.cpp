class Solution {
public:
    using ll =unsigned long long;
    int numDistinct(string s, string t) {
        int n =s.size(),m=t.size();
        vector<vector<ll>>dp(n+1,vector<ll>(m+1,0));
        for(int i = 0;i<=n;i++) dp[i][m]=1;
        
        for(int i =n-1;i>=0;i--){
            for(int j = m-1;j>=0;j--){
                dp[i][j] = dp[i+1][j];
                if(s[i]==t[j]){
                    dp[i][j] +=dp[i+1][j+1];
                }
            }
        }
        return dp[0][0];
    }
};