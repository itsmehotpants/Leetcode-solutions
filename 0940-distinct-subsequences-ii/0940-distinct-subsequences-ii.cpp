class Solution {
public:
    int distinctSubseqII(string s) {
        int n =s.size();
        const int mod=1e9 +7;
        vector<int>dp(n+1,1);
        vector<int>last(26,-1);
        for(int i=0;i<n;i++){
            dp[i+1] = (2*dp[i])%mod;
            if(last[s[i]-'a']!=-1){
                int j = last[s[i]-'a'];
                dp[i+1]=(dp[i+1]-dp[j]+mod)%mod;

            }
            last[s[i]-'a']=i;
        }
        return (dp[n]-1+mod)%mod;
    }
};