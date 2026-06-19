class Solution {
public:
    using ll = unsigned long long;

    int numDistinct(string s, string t) {
        int n = s.size(), m = t.size();

        vector<ll> next(m + 1, 0), curr(m + 1, 0);

        next[m] = 1; 

        for (int i = n - 1; i >= 0; i--) {
            curr[m] = 1;

            for (int j = m - 1; j >= 0; j--) {
                curr[j] = next[j]; 

                if (s[i] == t[j]) {
                    curr[j] += next[j + 1];
                }
            }

            next = curr;
        }

        return next[0];
    }
};