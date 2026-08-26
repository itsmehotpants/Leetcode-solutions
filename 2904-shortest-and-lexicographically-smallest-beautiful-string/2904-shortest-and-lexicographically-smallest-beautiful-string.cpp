class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        int n =s.length();
        for(int len= k;len<=n;len++){
            string res= "";
            for(int start = 0;start<=n-len;start++){
                string temp =s.substr(start,len);

                int ones=0;
                for(char &c:temp){
                    ones+=(c=='1')?1:0;
                }
                if(ones==k){
                    if(res.empty()||temp<res) res=temp;
                }
            }
        
        if(!res.empty()) return res;
        }
        return "";
    }
};