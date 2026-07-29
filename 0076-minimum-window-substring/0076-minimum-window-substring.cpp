class Solution {
public:
    string minWindow(string s, string t) {
        vector<int> mp(128, 0);

        for(char c : t) mp[c]++;

        int l = 0, need = t.size();
        int start = 0, len = INT_MAX;

        for(int r = 0; r < s.size(); r++){
            if(mp[s[r]] > 0) need--;
            mp[s[r]]--;
            while(need == 0){
                if(r - l + 1 < len){
                    len = r - l + 1;
                    start = l;
                }
                mp[s[l]]++;
                if(mp[s[l]] > 0) need++;
                l++;
            }
        }
        if(len == INT_MAX) return "";
        return s.substr(start, len);
    }
};