class Solution {
public:
using ll=long long;
const int mod =1e9+7;
ll dp[23][2][401];
ll solve(string &s, int idx,int tight, int sum,int min_sum, int max_sum){
    if(idx==s.size()) return (sum>=min_sum && sum<=max_sum);

    if(dp[idx][tight][sum]!=-1) return dp[idx][tight][sum];

    int limit  = (tight==1?s[idx]-'0':9);
    int ans=0;
    for(int i =0;i<=limit;i++){
        int newsum = sum+i;
        int newTight = tight && (i == limit);
        ans=(ans+solve(s,idx+1,newTight,newsum,min_sum,  max_sum))%mod;
    }
    return dp[idx][tight][sum]=ans ;
}

string decone(string s){
    int i =s.size()-1;
    while(i>=0&& s[i]=='0'){
        s[i]='9';
        i--;
    }
    if(i>=0) s[i]--;

    //  int pos=0;
    // while(pos+1<s.size() && s[pos]=='0')
    //     pos++;

    // return s.substr(pos);
    return s;


}
    int count(string l, string r, int min_sum, int max_sum) {
        memset(dp,-1,sizeof(dp));
        ll ans1=solve(r,0,1,0, min_sum,  max_sum);
        memset(dp,-1,sizeof(dp));
        string L = decone(l);
        ll ans2 =solve(L,0,1,0, min_sum,  max_sum);
       return ((ans1 - ans2) % mod + mod) % mod;
    }
};