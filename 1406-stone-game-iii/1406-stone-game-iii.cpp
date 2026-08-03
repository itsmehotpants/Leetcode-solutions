class Solution {
public:
    string stoneGameIII(vector<int>& val) {
         int n = val.size();
        int dp[4] = {0};
        for(int i = n - 1; i >= 0; --i){
            int best = val[i] - dp[(i + 1) & 3];
            if(i + 1 < n) best = max(best , val[i] + val[i + 1] - dp[(i + 2) & 3]);
            if(i + 2 < n) best = max(best , val[i] + val[i + 1] + val[i + 2] - dp[(i + 3) & 3]);
            dp[i & 3] = best;
        }
        if(dp[0] > 0) return "Alice";
        if(dp[0] < 0) return "Bob";
        return "Tie";
    }
};