class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> mp;
        int l = 0, res = 0;
        
        for (int r = 0; r < s.size(); r++) {
            mp[s[r]]++;
            while(mp[s[r]]>1){
                mp[s[l]]--;
                 if(mp[s[l]]==0) mp.erase(s[l]);
                l++;
            }
            res = max(res,r-l+1);
        
        }
        return res;
    }
};