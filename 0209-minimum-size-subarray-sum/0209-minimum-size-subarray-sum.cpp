class Solution {
public:
    int minSubArrayLen(int x, vector<int>& nums) {
        int n =nums.size();
        unordered_map<int,int>mp;
        int total  = accumulate(nums.begin(),nums.end(),0);
        if(x>total) return 0;
        int len =INT_MAX;
        int sum =0;
        int l=0,r=0;
        while(r<n){
            sum+=nums[r];
            while(sum>=x){
                len = min(len,r-l+1);
                sum-=nums[l];
                l++;
            }
            r++;
        }
        return len;
        
    }
};