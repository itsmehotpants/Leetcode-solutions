class Solution {
public:
    int maxValidPairSum(vector<int>& nums, int k) {
        long long ans = 0,mxm=0;
        for(int i = k;i<nums.size();i++){
            mxm =max(mxm,1LL*nums[i-k]);
            ans = max(ans,mxm+nums[i]);
        }
        return ans;
    }
};