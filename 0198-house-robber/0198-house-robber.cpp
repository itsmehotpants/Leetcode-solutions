class Solution {
public:

// int solve(int n,vector<int>nums,vector<int>&dp){
//     if(n<0) return 0;
//     if(dp[n]!=-1) return dp[n];
//     int take = nums[n]+solve(n-2,nums,dp);
//     int notTake= solve(n-1,nums,dp);
//     return dp[n]=max(take,notTake);
// }
    int rob(vector<int>& nums) {
        
        int n =nums.size();
        vector<int>dp(n+1,0);
        if(n==1) return nums[0];
        dp[0]=nums[0];
        dp[1] = max(nums[0],nums[1]);
        for(int i =2;i<n;i++){
            dp[i] = max(dp[i-1],dp[i-2]+nums[i]);

        }
        return dp[n-1];
    }
};