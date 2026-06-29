#include <cstring>
class Solution {
public:
    int dp[10001];

    bool dfs(vector<int>& nums, int i) {
        if (i == nums.size() - 1)
            return dp[i] = 1;

        if (dp[i] != -1)
            return dp[i];

        int end = min((int)nums.size() - 1, i + nums[i]);

        for (int j = i + 1; j <= end; j++) {
            if (dfs(nums, j))
                return dp[i] = 1;
        }

        return dp[i] = 0;
    }

    bool canJump(vector<int>& nums) {
        memset(dp, -1, sizeof(dp));
        return dfs(nums, 0);
    }
};