class Solution {
public:
    int f(int i, int j, vector<vector<int>>& mat, vector<vector<int>>& dp) {
        int m = mat.size(), n = mat[0].size();

        if (i >= m || j >= n || mat[i][j] == 1) return 0;

        if (i == m - 1 && j == n - 1) return 1;

        if (dp[i][j] != -1) return dp[i][j];

        return dp[i][j] = f(i + 1, j, mat, dp) + f(i, j + 1, mat, dp);
    }

    int uniquePathsWithObstacles(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        vector<vector<int>> dp(m, vector<int>(n, -1));
        return f(0, 0, mat, dp);
    }
};
