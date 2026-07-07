class Solution {
public:
    int minPairSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<int>sums;
        for(int i=0;i<nums.size()/2;i++){
            sums.push_back((nums[i]+nums[nums.size()-1-i]));
        }
        int ans  =*max_element(sums.begin(),sums.end());
        return ans;
    }
};