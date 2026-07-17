class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
        bool flag1 =true;//inc
        int n =nums.size();
        for(int i=0;i<n-1;i++){
            if(nums[i]>nums[i+1]) flag1 = false;
        }
         bool flag2 =true;//dec
        for(int i=0;i<n-1;i++){
            if(nums[i]<nums[i+1]) flag2 = false;
        }
        return flag1||flag2;

    }
};