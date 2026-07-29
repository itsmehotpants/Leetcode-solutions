class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n =s.size();
        unordered_map<char,int>mp;
       int left  = 0,best= 0;
        for(int right = 0;right<n;right++){
            mp[s[right]]++;
            while(mp[s[right]]>1){
                mp[s[left]]--;
                if(mp[s[left]]==0) mp.erase(s[left]);
                left++;

            }
            best = max(best,right-left+1);
        }
        return best;
    }
};