class Solution {
public:
    using ll= long long;

    ll dp[2][105][105];
    int n, m;

    ll f(int used, int prevht, int i, vector<vector<int>>& grid, vector<vector<ll>>& prefix){
        if(i==m) return 0;
        auto& cache= dp[used][prevht][i];

        if(cache!=-1) return cache;

        for(int ht=0; ht<=n; ht++){
            if(ht>=prevht){
                ll canGainPrev=(used)? 0: prefix[ht][i]-prefix[prevht][i];
                cache=max(cache, canGainPrev+f(0, ht, i+1, grid, prefix));
            }
            else{
                ll canGain=prefix[prevht][i+1]-prefix[ht][i+1];
                cache=max(cache, canGain+f(1, ht, i+1, grid, prefix));
                cache=max(cache, 0+f(0, ht, i+1, grid, prefix));
            }
        }

        return cache;
    }

    long long maximumScore(vector<vector<int>>& grid) {
        n=grid.size();
        m=grid[0].size();

        memset(dp, -1, sizeof(dp));
        vector<vector<ll>> prefix(n+1, vector<ll> (m+1));

        for(int j=1; j<=m; j++){
            for(int i=1; i<=n; i++){
                prefix[i][j]+=grid[i-1][j-1]+prefix[i-1][j];
            }
        }

        return f(0, 0, 0, grid, prefix);
    }
};