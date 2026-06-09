#define ll long long
class Solution {
public:
    long long maxTotalValue(vector<int>& nums, int k) {
        ll maxm=*max_element(nums.begin(),nums.end());
        ll minm=*min_element(nums.begin(),nums.end());
        return 1ll*k*(maxm-minm);
    }
};