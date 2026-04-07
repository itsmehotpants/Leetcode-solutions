class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        set<vector<int>> res; 
        sort(nums.begin(), nums.end());
        int n = nums.size();

        for (int i = 0; i < n - 2; i++) {
            int l = i + 1, r = n - 1;

            while (l < r) {
                int sum = nums[i] + nums[l] + nums[r]; 

                if (sum == 0) {
                    res.insert({nums[i], nums[l], nums[r]});
                    l++; 
                    r--;
                } 
                else if (sum < 0) {
                    l++;
                } 
                else {
                    r--;
                }
            }
        }
        vector<vector<int>> ans(res.begin(), res.end());
        return ans;
    }
};