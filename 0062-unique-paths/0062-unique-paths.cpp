class Solution {
public:
    int solve(int i, int j, int m, int n, vector<vector<int>>& t) {
        if(i == m-1 && j == n-1) {
            return 1; 
        }

        if(i < 0 || i >= m || j < 0 || j >= n) {
            return 0;
        }

        if(t[i][j] != -1) {
            return t[i][j];
        }

        int right = solve(i, j+1, m, n, t);
        int down  = solve(i+1, j, m, n, t);

        return t[i][j] = right + down;
    }

    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m+1, vector<int>(n+1, -1));
      //  if(m==1 && n==1) return 1;
      //  return solve(0, 0, m, n, t);
    dp[0][0]=1;
        for(int i =1;i<m;i++){
            dp[i][0]=1;
        }
        for(int j=1;j<n;j++) dp[0][j]=1;

        for(int i =1;i<m;i++){
            for(int j =1;j<n;j++){
                dp[i][j] =dp[i-1][j]+dp[i][j-1];
            }
        }
        return dp[m-1][n-1];
    }
};