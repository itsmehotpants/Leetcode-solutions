class Solution {
public:
    int longestCommonSubsequence(string s1, string s2) {
        int n = s1.size(), m = s2.size();
        vector<int> dp(m+1, 0);

        for(int i=1;i<=n;i++){
            int prevDiag = 0;
            for(int j=1;j<=m;j++){
                int temp = dp[j];
                if(s1[i-1] == s2[j-1])
                    dp[j] = 1 + prevDiag;
                else
                    dp[j] = max(dp[j], dp[j-1]);
                prevDiag = temp;
            }
        }
        return dp[m];
    }
};