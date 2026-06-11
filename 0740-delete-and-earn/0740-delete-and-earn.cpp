class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
int m = *max_element(nums.begin(),nums.end());
        vector<int>s(m+1,0);
        vector<int>dp(m+1,0);
        for(int i:nums){
            s[i]+=i;
        }
        dp[0]=s[0];
        dp[1]=max(s[0],s[1]);
       // cout<<freq[3];
        for(int i=2;i<=m;i++){
            dp[i] = max(dp[i-1],dp[i-2]+s[i]);
        }
        return dp[m];
    }
};