class Solution {
public:
    bool isGoodArray(vector<int>& nums) {
        int gcd = 0;
        for(int i = 0, n = nums.size(); i < n; ++i){
            gcd = __gcd(gcd , nums[i]);
            if(gcd == 1) return true;
        }
        return false;
    }
};