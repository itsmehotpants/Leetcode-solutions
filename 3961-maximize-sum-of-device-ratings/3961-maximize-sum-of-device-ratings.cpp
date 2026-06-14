class Solution {
public:
    long long maxRatings(vector<vector<int>>& u) {
        if (u[0].size() == 1) {
            long long s = 0;
            for (auto &v : u) s += v[0];
            return s;
        }

        long long s = 0;
        int mn = 1e9, mn2 = 1e9;

        for (auto &v : u) {
            sort(v.begin(), v.end());
            s += v[1];
            mn = min(mn, v[0]);
            mn2 = min(mn2, v[1]);
        }

        return s + mn - mn2;
    }
};