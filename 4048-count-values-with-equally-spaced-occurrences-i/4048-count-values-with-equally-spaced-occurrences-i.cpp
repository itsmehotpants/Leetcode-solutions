class Solution {
public:
    int countSpecialIntegers(vector<int>& nums) {
        vector<vector<int>> pos(101);

        for (int i = 0; i < nums.size(); i++) {
            pos[nums[i]].push_back(i);
        }

        int res = 0;

        for (int x = 1; x <= 100; x++) {
            if (pos[x].size() == 3 &&
                pos[x][1] - pos[x][0] == pos[x][2] - pos[x][1]) {
                res++;
            }
        }

        return res;
    }
};