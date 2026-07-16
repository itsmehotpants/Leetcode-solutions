# define ll long long 
class Solution {
public:
    long long gcdSum(vector<int>& nums) {
        int n =nums.size(),mx=0;
        vector<int>a(n);
        for(int i=0;i<n;i++){
            mx=max(mx,nums[i]);
            a[i]=gcd(nums[i],mx);
        }
        sort(a.begin(),a.end());

        ll ans=0;
        for(int l =0,r=n-1;l<r;l++,r--){
            ans+=gcd(a[l],a[r]);
        }
        return ans;
    }
};