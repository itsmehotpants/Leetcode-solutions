class Solution {
public:
    int strStr(string s, string t) {

        if(s.length()<t.length()) return -1;
        for(int i =0;i<=s.length()-t.length();i++){
            if(s.substr(i,t.length())==t) return i;
        }
        return -1;
        
    }
};