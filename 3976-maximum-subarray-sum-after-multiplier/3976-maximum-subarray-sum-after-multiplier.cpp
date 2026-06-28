class Solution {
public:
    using ll =long long;

    ll f(vector<int>& nums, int k,bool mult){
        const ll neg=-4e18;
        ll dp0=neg,dp1=neg,dp2=neg,ans=neg;

        for(ll x:nums){
            ll y = mult?x*k:x/k;
            ll n0  =max(x,dp0+x);
            ll n1 = max({y,dp0+y,dp1+y});
            ll n2 = max(dp1+x,dp2+x);

            dp0 =n0;
            dp1= n1;
            dp2=n2;
            ans = max({ans,dp0,dp1,dp2});
        }
        return ans;
    }
    long long maxSubarraySum(vector<int>& nums, int k) {
        return max(f(nums,k,true),f(nums,k,false));
    }
};