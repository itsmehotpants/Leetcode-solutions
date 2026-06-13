class Solution {
public:
    static constexpr int mod = 1e9 + 7;
int dp[51][101][101];
    int N,M,K;

    int solve(int pos,int cost,int maxm){

        if(cost > K) return 0;

        if(pos == N){
            return cost == K;
        }
        if(dp[pos][cost][maxm]!=-1) return dp[pos][cost][maxm];

        long long result = 0;

        for(int num=1; num<=M; num++){

            if(num > maxm){
                result = (result +
                          solve(pos+1,cost+1,num)) % mod;
            }
            else{
                result = (result +
                          solve(pos+1,cost,maxm)) % mod;
            }
        }

        return dp[pos][cost][maxm]=  result;
    }

    int numOfArrays(int n, int m, int k) {
        N=n;
        M=m;
        K=k;
        memset(dp,-1,sizeof(dp));

        return solve(0,0,0);
    }
};