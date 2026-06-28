class Solution {
public:
    using ll =long long;
    long long maxSum(vector<int>& nums, int k, int mul) {
        sort(nums.rbegin(),nums.rend());
        ll ans= 0;
        int minm = min(k,mul);
        for(int i =0;i<minm;i++){
            ans+=(ll)nums[i]*(mul-i);
            
        }
        for(int i =minm;i<k;i++){
            ans+=nums[i];
        }
        return ans;
    }
};