class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        auto ub = upper_bound(nums.begin(),nums.end(),target);
        auto lb = lower_bound(nums.begin(),nums.end(),target);
        int  l= lb-nums.begin();
        int  r=  ub-nums.begin()-1;
        if(lb==nums.end()|| nums[l]!=target) return{-1,-1};
        return {l,r};
        


    }
};