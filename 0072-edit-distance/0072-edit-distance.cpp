class Solution {
public:
    int n, m;
    int dp[501][501];

    int solve(string& s1, string& s2, int i, int j) {

        if(i == n) return m - j;
        if(j == m) return n - i;

        if(dp[i][j] != -1)
            return dp[i][j];

        if(s1[i] == s2[j])
            return dp[i][j] = solve(s1, s2, i + 1, j + 1);

        return dp[i][j] = 1 + min({
            solve(s1, s2, i + 1, j),     // delete
            solve(s1, s2, i, j + 1),     // insert
            solve(s1, s2, i + 1, j + 1)  // replace
        });
    }

    int minDistance(string s1, string s2) {
        n = s1.size();
        m = s2.size();

        memset(dp, -1, sizeof(dp));

        return solve(s1, s2, 0, 0);
    }
};