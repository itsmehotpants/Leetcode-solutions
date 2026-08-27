class Solution {
public:
    string lexGreaterPermutation(string s, string t) {
        int c[26]{};
        for(char x:s)c[x-'a']++;
        for(char x:t)c[x-'a']--;
        for(int i=t.size()-1;i>=0;i--){
            c[t[i]-'a']++;
            bool ok=1;
            for(int x:c) if(x<0) ok=0;
            if(!ok) continue;
            for(int j=t[i]-'a'+1;j<26;j++) if(c[j]){
                string r=t.substr(0,i)+char('a'+j);
                c[j]--;
                for(int k=0;k<26;k++) r+=string(c[k],'a'+k);
                return r;
            }
        }
        return "";
    }
};