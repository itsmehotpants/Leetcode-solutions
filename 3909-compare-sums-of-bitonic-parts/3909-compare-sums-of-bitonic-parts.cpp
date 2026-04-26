class Solution {
public:
    int compareBitonicSums(vector<int>& nums) {
        int idx=-1;
        long long lsum=0;
        int n =nums.size();
        for(int i =0;i<n-1;i++){
            lsum+=nums[i];
            if(nums[i]>nums[i+1]){
                idx = i;
                break;
            }

        }
        for(int i=idx;i<n;i++){
            lsum-=nums[i];
        }
        if(lsum<0) return 1;
        if(lsum>0) return 0;
        return -1;
    }
};