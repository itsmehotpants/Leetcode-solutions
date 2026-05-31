class Solution {
public:
    vector<int> maximumMEX(vector<int>& nums) {
        int n = nums.size();

        vector<int> freq(n + 2);
        for (int x : nums)
            if (x <= n) freq[x]++;

        set<int> miss;
        for (int i = 0; i <= n + 1; i++)
            if (!freq[i]) miss.insert(i);

        vector<int> ans;
        int i = 0;

        while (i < n) {
            int mex = *miss.begin();

            if (mex == 0) {
                ans.push_back(0);

                if (nums[i] <= n && --freq[nums[i]] == 0)
                    miss.insert(nums[i]);

                i++;
                continue;
            }

            set<int> seen;
            int j = i;

            while (seen.size() < mex) {
                if (nums[j] < mex)
                    seen.insert(nums[j]);

                if (nums[j] <= n && --freq[nums[j]] == 0)
                    miss.insert(nums[j]);

                j++;
            }

            ans.push_back(mex);
            i = j;
        }

        return ans;
    }
};