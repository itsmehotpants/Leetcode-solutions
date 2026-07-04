class Solution {
public:
    bool isMiddleElementUnique(vector<int>& nums) {
        int m = nums[nums.size()/2], f=0;
        for(int i:nums) f+=(i==m);
        return f==1;
    }
};