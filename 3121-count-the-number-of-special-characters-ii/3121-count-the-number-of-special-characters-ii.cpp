class Solution {
public:
    int numberOfSpecialChars(string w) {
        int count=0;
        unordered_map<char,int>m;
        for(int i=0;i<w.size();i++){
            if(w[i]>='a'&& w[i]<='z') m[w[i]]=i;
            else if (w[i]>='A' && w[i] <='Z' && !m.count(w[i])) m[w[i]]=i;
        }

        for(char ch='a' ;ch<='z';ch++){
            if(m.count(ch) && m.count(ch-'a'+'A') && m[ch]<m[ch-'a'+'A']) count++;
        }
        return count;
    }
};