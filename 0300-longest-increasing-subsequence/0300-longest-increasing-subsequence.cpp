class Solution {
public:

int n;
int dp[2501][2501];
int solve(int i,int p,vector<int>&nums){
    if(i>=n) return 0;
    int take=0;
    if(p!=-1 && dp[i][p]!=-1) return dp[i][p];
    if(p==-1||nums[p]<nums[i]){
      take=1+solve(i+1,i,nums);
    }
    int skip = solve(i+1,p,nums);
    if(p!=-1) dp[i][p]=max(take,skip);
    return max(take,skip);
}
    int lengthOfLIS(vector<int>& nums) {
        n =nums.size();
        memset(dp,-1,sizeof(dp));
         return solve(0,-1,nums);
        // return dp[2500][2500];
    }
};