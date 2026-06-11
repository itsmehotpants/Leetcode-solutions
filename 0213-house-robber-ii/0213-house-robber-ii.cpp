class Solution {
public:
vector<int>dp;
int solve(int i , int start,vector<int>&nums){
    if(i<start) return 0;
    if(i==start) return nums[start];
    if(dp[i]!=-1) return dp[i];
    int take = nums[i]+solve(i-2,start,nums);
    int nottake = solve(i-1,start,nums);
    return dp[i]= max(take,nottake);
}
    int rob(vector<int>& nums) {
        int n= nums.size();
        if(n==1) return nums[0];
        dp.assign(n+1,-1);
        int ans1 = solve(n-2,0,nums);
        dp.assign(n+1,-1);
        int ans2  = solve(n-1,1,nums);
        return max(ans1,ans2);

    }
};