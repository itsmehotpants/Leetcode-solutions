class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();

        vector<vector<bool>> dp(n, vector<bool>(n, false));

        int start = 0;
        int maxLen = 1;

        for(int L = 1; L <= n; L++) {
            for(int i = 0; i + L - 1 < n; i++) {

                int j = i + L - 1;

                if(s[i] == s[j] && (L <= 2 || dp[i+1][j-1])) {
                    dp[i][j] = true;

                    if(L > maxLen) {
                        maxLen = L;
                        start = i;
                    }
                }
            }
        }

        return s.substr(start, maxLen);
    }
};