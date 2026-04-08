class Solution {
public:
    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        int mod = 1e9 +7;
        for (auto q : queries) {
            int l = q[0], r = q[1], k = q[2], v = q[3];
            for (int i = l ; i <= r; i += k) {
                nums[i] = (1ll*nums[i] * v) % mod;
            }
        }
        int ans  = nums[0];
        for(int i=1;i<nums.size();i++){
            ans^=nums[i];
        }
        return ans;
    }
};