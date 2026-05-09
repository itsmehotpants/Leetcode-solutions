class Solution {
public:
    int minFlips(string s) {
        int cntr = count(s.begin(), s.end(), '1');
        int cnt0 = count(s.begin(), s.end(), '0');
        int cntl = 0;
        int ans = 0;
        for(auto &i : s) {
            if(i == '1') {
                cntl++;
                cntr--;
            } else {
                ans = max({ans, max(0, cntl - 1) + max(0, cntr - 1)});
            }
        }
        return min(cnt0, ans);
    }
};