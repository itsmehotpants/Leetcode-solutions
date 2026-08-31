class Solution {
public:
int dp[101]={0};
    int cal(int i,string s){
        if(i==s.size()) return 1;
        if(dp[i]!=0) return dp[i];
int ans=0;
        if(s[i]!='0') ans+=cal(i+1,s);
        if(i+1<s.size() && (s[i]=='1' || (s[i]=='2' && s[i+1]<='6'))){
            ans+=cal(i+2,s);
        } 
        return dp[i]=ans;

        
    }
    int numDecodings(string s) {
        
        
        int n=s.size();
        // int i=0;
        // while(s[i]=='0'){
        //     i++;
        // }
        return cal(0,s);
    }
};