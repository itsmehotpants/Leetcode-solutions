class Solution {
public:
    vector<int> gcdValues(vector<int>& nums, vector<long long>& queries) {
        int mx = *max_element(nums.begin(), nums.end());

        vector<long long> freq(mx + 1, 0);
        for (int x : nums) {
            freq[x]++;
        }

        vector<long long> cnt(mx + 1, 0);
        for (int d = 1; d <= mx; d++) {
            for (int m = d; m <= mx; m += d) {
                cnt[d] += freq[m];
            }
        }

        vector<long long> pairDiv(mx + 1, 0);
        for (int d = 1; d <= mx; d++) {
            pairDiv[d] = cnt[d] * (cnt[d] - 1) / 2;
        }

        vector<long long> exact(mx + 1, 0);
        for (int d = mx; d >= 1; d--) {
            exact[d] = pairDiv[d];
            for (int m = 2 * d; m <= mx; m += d) {
                exact[d] -= exact[m];
            }
        }

        vector<long long> pref(mx + 1, 0);
        for (int d = 1; d <= mx; d++) {
            pref[d] = pref[d - 1] + exact[d];
        }

        vector<int> ans;
        for (long long q : queries) {
            int g = upper_bound(pref.begin() + 1, pref.end(), q) - pref.begin();
            ans.push_back(g);
        }

        return ans;
    }
};