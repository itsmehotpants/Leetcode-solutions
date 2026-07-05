class Solution {
public:
    int maxDigitRange(vector<int>& nums) {
        int mx=-1,ans=0;
        vector<int>v(nums.size());
        for(int i =0;i<nums.size();i++){
            int h=0,l=9,x=nums[i];
            while(x){
                h = max(h,x%10);
                l=min(l,x%10);
                x/=10;
                
            }
            v[i]= h-l;
            mx=max(mx,v[i]);
            
        }
        for(int i =0;i<nums.size();i++){
            if(v[i]==mx) ans+=nums[i];
        }
        return ans;
    }
};