class Solution {
public:
    int countSubstrings(string s) {
        int n = s.size();

        vector<vector<int>> dp(n, vector<int>(n, 0));
        int cnt = 0;

    //  for(int L = 1; L <= n; L++) {
    //         for(int i = 0; i + L - 1 < n; i++) {

    //             int j = i + L - 1;

    //             if(i == j) {
    //                 dp[i][j] = 1;
    //             }
    //             else if(i + 1 == j) {
    //                 dp[i][j] = (s[i] == s[j]);
    //             }
    //             else {
    //                 dp[i][j] =
    //                     (s[i] == s[j]) && dp[i + 1][j - 1];
    //             }
    //             cnt += dp[i][j];
    //         }
    //     }
    for(int L=1; L<=n; L++){
    for(int i=0; i+L-1<n; i++){
        int j=i+L-1;

        if(s[i]==s[j] && (L<=2 || dp[i+1][j-1]))
            dp[i][j]=1;

        cnt += dp[i][j];
    }
}
        return cnt;
    }
};