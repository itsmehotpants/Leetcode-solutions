class Solution {
public:
    vector<vector<int>> dp;

    int solve(int i, int target, vector<int>& nums) {

        if(i == 0) {

            if(target == 0 && nums[0] == 0)
                return 2;

            if(target == 0 || target == nums[0])
                return 1;

            return 0;
        }

        if(dp[i][target] != -1)
            return dp[i][target];

        int notTake = solve(i - 1, target, nums);

        int take = 0;

        if(nums[i] <= target)
            take = solve(i - 1, target - nums[i], nums);

        return dp[i][target] = take + notTake;
    }

    int findTargetSumWays(vector<int>& nums, int target) {

        int n = nums.size();

        int sum = accumulate(nums.begin(), nums.end(), 0);

        if(abs(target) > sum)
            return 0;

        if((sum + target) % 2 != 0)
            return 0;

        int k = (sum + target) / 2;

        dp.resize(n, vector<int>(k + 1, -1));

        return solve(n - 1, k, nums);
    }
};