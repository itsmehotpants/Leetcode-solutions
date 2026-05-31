class Solution {
public:
    int maximizeSum(vector<int>& nums, int k) {
        int maxm = *max_element(nums.begin(),nums.end()), ans = 0;
        for(int i = 0; i < k; i++){
            ans += maxm++;
        }
        return ans;
    }
};