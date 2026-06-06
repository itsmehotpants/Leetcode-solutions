class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return {0};

        vector<int> leftSum(n, 0), rightSum(n, 0);
        int lsum = 0, rsum = 0;

        for(int i = 1; i < n; ++i) {
            lsum += nums[i - 1];
            leftSum[i] = lsum;
        }

        for(int i = n-2; i > -1; --i) {
            rsum += nums[i + 1];
            rightSum[i] = rsum;
        }

        for(int i = 0; i < n; ++i) {
            nums[i] = abs(leftSum[i] - rightSum[i]);
        }
        return nums;
    }
};