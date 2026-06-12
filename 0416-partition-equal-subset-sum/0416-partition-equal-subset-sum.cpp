class Solution {
public:

vector<vector<int>>dp;
bool solve(int i , int target, vector<int>&nums){
    if(target==0) return true;
    if(i<0) return false; 
if(dp[i][target]!=-1) return dp[i][target];
    int nottake = solve(i-1,target,nums);
    int take =0;
    if(target>=nums[i]) {
        take = solve(i-1,target-nums[i],nums);
    }
    return dp[i][target]= take||nottake;
}
    bool canPartition(vector<int>& nums) {
        
        int n =nums.size();
        int sum = accumulate(nums.begin(),nums.end(),0);
        if(sum%2) return false;
        
        else {
            int target=sum/2;
        dp.resize(n,vector<int>(target+1,-1));
           return solve(n-1,target,nums);
        }
    }
};