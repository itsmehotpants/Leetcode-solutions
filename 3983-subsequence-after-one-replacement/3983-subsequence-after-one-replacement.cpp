class Solution {
public:
    bool canMakeSubsequence(string s, string t) {
        int n =s.size(),i0=0,i1=0;
        for(char c:t){
            if(i1<n&&s[i1]==c) i1++;
            i1=max(i1,min(n,i0+1));

            if(i0<n && s[i0]==c) i0++;
            
        }
        // cout<<i1;
        return i1==n;
    }
};