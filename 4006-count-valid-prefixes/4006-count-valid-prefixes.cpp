class Solution {
public:
    int countValidPrefixes(string s) {
        int cnt0=0,cnt1=0;
        int ans=0;
        int l=0;
        while(l<s.size()){
            if(s[l]-'0'==0) cnt0++;
            else cnt1++;

            if(abs(cnt1-cnt0)<2) ans++;
            l++;
        }
        return ans;
       
    }
};