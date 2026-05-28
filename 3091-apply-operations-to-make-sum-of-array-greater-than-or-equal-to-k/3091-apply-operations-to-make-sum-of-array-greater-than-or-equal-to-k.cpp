class Solution {
public:
    int minOperations(int k) {

        if (k == 1)
            return 0;

        int ans = INT_MAX;
        for (int n = 1; n <= k; n++) {

            int t = ceil(float(k) / n);
            ans = min(ans, n - 1 + t - 1);
        }

        return ans;
    }
};