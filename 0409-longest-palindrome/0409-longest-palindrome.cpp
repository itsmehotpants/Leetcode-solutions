class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char,int>mp;
        for(char c:s){
            mp[c]++;
        }
        int oddmx = 0;
        int len = 0;
        bool hasodd = false;
        for(auto& [val,cnt]:mp){
            if(cnt%2==0) len+=cnt;
            else{
                len+=cnt-1;
                hasodd =true;
            }
        }
        if(hasodd) len++;
        return len;
    }
};