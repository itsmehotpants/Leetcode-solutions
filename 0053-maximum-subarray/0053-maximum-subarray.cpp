class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if(nums.size()==1) return nums[0];
        int sum=0;
int ans =nums[0];
        for(int i =0;i<nums.size();i++){
            sum+=nums[i];
            ans =max(ans,sum);
            if(sum<0) {
                ans= max(ans,sum);
                sum = 0;
            }
        }
        return ans;
    }
};
