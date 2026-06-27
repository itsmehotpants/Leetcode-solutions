class Solution {
public:
    int dp[11][1024][2][2];

    int solve(string &s, int idx, int mask, int tight, int lz) {
        if (idx == s.size())
            return !lz;  
        if (dp[idx][mask][tight][lz] != -1)
            return dp[idx][mask][tight][lz];

        int limit = tight ? s[idx] - '0' : 9;
        int ans = 0;

        for (int digit = 0; digit <= limit; digit++) {
            int newTight = tight && (digit == limit);

            if (lz && digit == 0) {
                ans += solve(s, idx + 1, mask, newTight, 1);
            } else {
                if (mask & (1 << digit))
                    continue;

                ans += solve(s, idx + 1, mask | (1 << digit), newTight, 0);
            }
        }

        return dp[idx][mask][tight][lz] = ans;
    }

    int countSpecialNumbers(int n) {
        memset(dp, -1, sizeof(dp));
        string s = to_string(n);
        return solve(s, 0, 0, 1, 1);
    }
};