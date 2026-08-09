// class Solution {
// public:
//     int maxEnvelopes(vector<vector<int>>& env) {
//         sort(env.begin(),env.end());
//         int n =env.size();
//         vector<int>dp(n+1,1);
//         int maxm=1;
//         for(int i =1;i<n;i++){
//             for(int j =0;j<i;j++){
//                 if(env[i][0]>env[j][0] && env[i][1]>env[j][1] && dp[j]+1>dp[i]){
//                     dp[i]=dp[j]+1;
//                 }
//                 maxm=max(maxm,dp[i]);
//             }
//         }
//         return maxm;
//     }
// };

class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& env) {

        // width increasing, height decreasing for equal width
        sort(env.begin(), env.end(), [](const vector<int>& a, const vector<int>& b) {
            if (a[0] == b[0])
                return a[1] > b[1];
            return a[0] < b[0];
        });

        vector<int> lis;

        for (auto& e : env) {
            int h = e[1];

            auto it = lower_bound(lis.begin(), lis.end(), h);

            if (it == lis.end())
                lis.push_back(h);
            else
                *it = h;
        }

        return lis.size();
    }
};