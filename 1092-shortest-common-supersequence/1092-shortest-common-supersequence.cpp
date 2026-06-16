class Solution {
public:
    int m, n;
    vector<vector<int>> dp;

    int solve(string& s1, string& s2, int i, int j) {
        if(i == m) return n - j;
        if(j == n) return m - i;

        if(dp[i][j] != -1)
            return dp[i][j];

        if(s1[i] == s2[j])
            return dp[i][j] = 1 + solve(s1, s2, i + 1, j + 1);

        return dp[i][j] = 1 + min(
            solve(s1, s2, i + 1, j),
            solve(s1, s2, i, j + 1)
        );
    }

    string build(string& s1, string& s2, int i, int j) {
        if(i == m) return s2.substr(j);
        if(j == n) return s1.substr(i);

        if(s1[i] == s2[j])
            return s1[i] + build(s1, s2, i + 1, j + 1);

        if(solve(s1, s2, i + 1, j) <= solve(s1, s2, i, j + 1))
            return s1[i] + build(s1, s2, i + 1, j);

        return s2[j] + build(s1, s2, i, j + 1);
    }

    string shortestCommonSupersequence(string s1, string s2) {
        m = s1.size();
        n = s2.size();

        dp.assign(m, vector<int>(n, -1));

        solve(s1, s2, 0, 0);

        return build(s1, s2, 0, 0);
    }
};