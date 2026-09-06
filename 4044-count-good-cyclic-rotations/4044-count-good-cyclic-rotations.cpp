class Solution {
public:
    int countGoodRotations(vector<int>& nums) {
        int n=nums.size();
        

        long long fir=0,sec=0;
        
        for(int i=0;i<n;i++){
            if(i<n/2) fir += nums[i];
            else sec += nums[i];
        }

        int ans=0;

        for(int i=0;i<n;i++){
            if(fir>sec) ans++;

            fir-=nums[i];
            fir+=nums[(i+n/2)%n];

            sec-=nums[(i+n/2)%n];
            sec+=nums[i];
        }

        return ans;
    }
};