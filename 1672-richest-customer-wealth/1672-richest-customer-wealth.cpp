class Solution {
public:
    int maximumWealth(vector<vector<int>>& ac) {
        int ans = 0;
        for (auto &c : ac)
            ans = max (ans, accumulate(c.begin(), c.end(), 0));
        
        return ans;
    }
};