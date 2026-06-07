class Solution {
public:
    using ll=long long;
    long long maxTotal(vector<int>& nums, string s) {
        const ll minm=LLONG_MIN;
        ll f=0,g=minm;
        for(int i=0;i<nums.size();i++){
            if(s[i]=='0'){
                f=max(f,g);
                g=minm;
                continue;
                
            }
            ll stay = max(f,g)+nums[i];
            ll left =minm;
            if(i>0&&f!=minm){
                left=f+nums[i-1];
            }
            f=left,g=stay;
        }
        return max(f,g);
    }
};