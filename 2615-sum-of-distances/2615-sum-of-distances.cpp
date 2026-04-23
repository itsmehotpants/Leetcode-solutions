#define ll long long
class Solution {
public:
    vector<long long> distance(vector<int>& nums) {
        map<int, vector<int>> I;
        for (int i = 0; i < nums.size(); i++) {
            I[nums[i]].push_back(i);
        }

        vector<ll> ans(nums.size());
        for (auto &[v, a] : I) {
            ll sum = 0, n = a.size();
            for (int i = 0; i < n; i++) {
                sum += a[i] - a[0];
            }

            ans[a[0]] = sum;
            for (int i = 1; i < n; i++) {
                sum += (2 * i - n) * (a[i] - a[i-1]);
                ans[a[i]] = sum;
            }
        }

        return ans;
    }
};