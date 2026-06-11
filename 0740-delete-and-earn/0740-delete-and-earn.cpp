class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {

        int m = *max_element(nums.begin(), nums.end());

        vector<int> s(m + 1, 0);

        for(int x : nums)
            s[x] += x;

        int prev2 = s[0];
        int prev1 = max(s[0], s[1]);

        for(int i = 2; i <= m; i++) {

            int cur = max(
                prev1,
                s[i] + prev2
            );

            prev2 = prev1;
            prev1 = cur;
        }

        return prev1;
    }
};