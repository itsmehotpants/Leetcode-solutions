class Solution {
public:

    bool canMake(vector<int>& v, int mid, int m, int k) {
        int cnt = 0, bouquets = 0;

        for (int i = 0; i < v.size(); i++) {
            if (v[i] <= mid) {
                cnt++;
                if (cnt == k) {
                    bouquets++;
                    cnt = 0;
                }
            } else {
                cnt = 0;
            }
        }
        return bouquets >= m;
    }

    int minDays(vector<int>& v, int m, int k) {
        int n = v.size();
        if (n < (long long)m * k) return -1;

        int l = 1;
        int r = *max_element(v.begin(), v.end());
        int ans = -1;

        while (l <= r) {
            int mid = l + (r - l) / 2;

            if (canMake(v, mid, m, k)) {
                ans = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        return ans;
    }
};