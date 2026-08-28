class Solution {
public:
    string lexPalindromicPermutation(string s, string target) {
        int cnt[26]{}, n = s.size();
        for (char c : s) {
            ++cnt[c - 'a'];
        }
        string res(n, '#');
        for (int i = 0; i < 26; ++i) {
            if (!(cnt[i] & 1)) continue;
            if (res[n / 2] != '#') return "";
            res[n / 2] = 'a' + i;
        }

        int m = n / 2;
        auto dfs = [&] (this auto&& dfs, int i, bool big) -> bool {
            if (i == m) return (big || res > target);
            int base = target[i] - 'a';
            for (int j = big ? 0 : base; j < 26; ++j) {
                if (cnt[j] < 2) continue;
                cnt[j] -= 2;
                res[i] = res[n - 1 - i] = 'a' + j;
                if (dfs(i + 1, big || j > base)) return true;
                cnt[j] += 2;
            }
            return false;
        };

        if (!dfs(0, false)) return "";
        return res;
    }
};