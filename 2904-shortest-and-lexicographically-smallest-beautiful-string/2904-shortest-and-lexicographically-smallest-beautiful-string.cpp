class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        int n =s.length(),i=0,j=0,ones=0;
        string res="";

        while(j<n){
            if(s[j]=='1') ones++;
            while(ones>k || s[i]=='0'){
                if(s[i]=='1') ones--;
                i++;
            }
            if(ones==k){
                string temp =s.substr(i,j-i+1);
                if(res.empty() || res.length()>j-i+1 || (temp.length()==res.length() && temp<res)){
                    res=temp;
                }
            }
            j++;
        }
        return res;
    }
};