class Solution {
public:
    vector<int> separateDigits(vector<int>& nums) {
        vector<int> ans{};
        string str{};
        for(int num : nums)
        {
            if(num < 10)
                ans.push_back(num);
            else
            {
                str = to_string(num);
                for(char ch : str)
                    ans.push_back(ch - '0');
            }
        }
        return ans;
    }
};