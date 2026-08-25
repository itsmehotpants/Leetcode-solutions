class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int>mp;
        int n =s.size();
        int  l =0;
        int len =0;
        for(int r= 0;r<n;r++){
            mp[s[r]]++;
            while(mp[s[r]]>1){
                mp[s[l]]--;
               if(mp[s[l]]==0) mp.erase(s[l]);
                l++;
            }
               len  = max(len,r-l+1);

        }
        return len;
    }
};