class Solution {
public:
    long long numOfSubsequences(string s) {
        int n = s.size();

        long long countL = 0, countLC = 0, countLCT = 0;
        for (char ch : s) {
            if (ch == 'L') countL++;
            else if (ch == 'C') countLC += countL;
            else if (ch == 'T') countLCT += countLC;
        }

        vector<long long> prefixL(n + 1, 0), prefixLC(n + 1, 0);
        for (int i = 0; i < n; i++) {
            prefixL[i+1] = prefixL[i] + (s[i] == 'L' ? 1 : 0);
            prefixLC[i+1] = prefixLC[i] + (s[i] == 'C' ? prefixL[i] : 0);
        }
        vector<long long> suffixT(n + 1, 0), suffixCT(n + 1, 0);
        for (int i = n - 1; i >= 0; i--) {
            suffixT[i] = suffixT[i+1] + (s[i] == 'T' ? 1 : 0);
            suffixCT[i] = suffixCT[i+1] + (s[i] == 'C' ? suffixT[i+1] : 0);
        }

        long long maxGain = 0;
        for (int i = 0; i <= n; i++) {
            long long gainL = suffixCT[i];
            long long gainC = prefixL[i] * suffixT[i];
            long long gainT = prefixLC[i];
            maxGain = max({maxGain, gainL, gainC, gainT});
        }

        return countLCT + maxGain;
    }
};