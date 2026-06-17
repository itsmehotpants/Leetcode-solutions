class Solution {
public:
    int dp[201][201];

    int solve(vector<vector<int>>& mat, int i=0, int j=0) {
        int n = mat.size(), m = mat[0].size();

        if(i == n || j == m) return 1e9;

        if(dp[i][j] != 1e9) return dp[i][j];

        if(i == n-1 && j == m-1) {
            return dp[i][j] =
                (mat[i][j] <= 0) ? -mat[i][j] + 1 : 1;
        }

        int right = solve(mat, i, j+1);
        int down  = solve(mat, i+1, j);

        int need = min(right, down) - mat[i][j];

        return dp[i][j] = max(1, need);
    }

    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        fill(&dp[0][0], &dp[0][0] + 201*201, 1e9);
        return solve(dungeon);
    }
};