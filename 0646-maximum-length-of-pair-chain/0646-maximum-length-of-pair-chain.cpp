class Solution {
public:
    int n;
    int dp[1001][1001];

    int solve(int i, int j, vector<vector<int>>& pairs) {
        if(i >= n) return 0;

        if(dp[i][j + 1] != -1)
            return dp[i][j + 1];

        int skip = solve(i + 1, j, pairs);

        int take = 0;
        if(j == -1 || pairs[i][0] > pairs[j][1]) {
            take = 1 + solve(i + 1, i, pairs);
        }

        return dp[i][j + 1] = max(take, skip);
    }

    int findLongestChain(vector<vector<int>>& pairs) {
        n = pairs.size();

        sort(pairs.begin(), pairs.end());

        memset(dp, -1, sizeof(dp));

        return solve(0, -1, pairs);
    }
};