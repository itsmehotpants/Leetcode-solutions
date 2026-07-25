class Solution {
public:
    int maxProduct(int n) {
        int prod=1;
        string s = to_string(n);
        sort(s.begin(),s.end());
        
        int sz =s.size();
        int n1 = s[sz-1] - '0',n2 = s[sz-2]-'0';
        return n1*n2;
        // for(char c:s){
        //     int t = c-'0';
        //     if(t!=0) prod*=t;
        //     else continue;
        // }
        // return prod;

    }
};