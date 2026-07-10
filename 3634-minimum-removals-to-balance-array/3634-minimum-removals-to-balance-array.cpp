class Solution {
public:
    int minRemoval(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());

        int n = nums.size();
        int l = 0, len = 0;

        for (int r = 0; r < n; ++r) {
            while (l <= r && (long long)nums[r] > (long long)nums[l] * k)
                ++l;
                len =max( r - l + 1,len);
        }
        return n - len;
    }
};