class Solution {
public:
    vector<int> scoreValidator(vector<string>& events) {
        vector<int> ans = {0, 0}; 
        
        for (auto it : events) {
            if (it == "W") ans[1]++;
            else if (it == "WD") ans[0]++;
            else if (it == "NB") ans[0]++;
            else ans[0] += stoi(it);

            if (ans[1] == 10) break;
        }

        return ans;
    }
};