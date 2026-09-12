class Solution {
public:
    int countSpecialIntegers(vector<int>& nums) {
        unordered_map<int, int> mp;

        for (int x : nums) {
            mp[x]++;
        }

        int res = 0;

        for (auto &[x, freq] : mp) {
            if (freq != 3) continue;

            int f1 = -1, s1 = -1, t1 = -1;

            for (int i = 0; i < nums.size(); i++) {
                if (nums[i] == x) {
                    if (f1 == -1) f1 = i;
                    else if (s1 == -1) s1 = i;
                    else {
                        t1 = i;
                        break;
                    }
                }
            }

            if (s1 - f1 == t1 - s1) {
                res++;
            }
        }

        return res;
    }
};