class Solution {
public:
   
    int lengthOfLIS(vector<int>& nums) {
int n =nums.size();
vector<int>dp(n,1);
int ans=1;
    for(int i =0;i<n;i++){
        for(int j=0;j<i;j++){
            if(nums[i]>nums[j]){
                dp[i] = max(dp[i],dp[j]+1);
                ans= max(ans,dp[i]);
            }}}
            return ans;
        }
    
    };
    // int solve(vector<int>& nums, int i, int prev_i) {
    //     if(i >= size(nums)) return 0;
    //     if(dp[prev_i+1] != -1) return dp[prev_i+1];
    //     int take = 0, dontTake = solve(nums, i + 1, prev_i);
    //     if(prev_i == -1 || nums[i] > nums[prev_i])
    //         take = 1 + solve(nums, i + 1, i);
    //     return dp[prev_i+1] = max(take, dontTake);
    // }
// };