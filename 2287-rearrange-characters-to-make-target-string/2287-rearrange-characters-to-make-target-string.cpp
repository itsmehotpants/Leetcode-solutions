class Solution {
public:
    int rearrangeCharacters(string text, string target) {
         unordered_map<char,int>freq,txt;
        int ans =INT_MAX;
        string s  =target;
        for(char c:s) freq[c]++;
        for(char c:text) txt[c]++;

        for(auto c: freq){
            int q =txt[c.first]/freq[c.first];
            ans = min(ans,q);
        }
        return ans;
    }
};