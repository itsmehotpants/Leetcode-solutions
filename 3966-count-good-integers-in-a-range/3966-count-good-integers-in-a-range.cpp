class Solution {
public:
using ll =long long;

int k;
ll dp[16][11][2][2];
ll f(int idx,int prev,int tight,int lz,string s,int k){
    if(idx>=s.length()) return !lz;
    if(dp[idx][prev][tight][lz]!=-1) return dp[idx][prev][tight][lz];
    int up =s[idx]-'0';
    if(!tight) up=9;
    ll cnt=0;
    for(int dig=0;dig<=up;dig++){
        int newtight= tight&&(dig==up);
        int  newlz = lz&&(dig==0);
        if(newlz){
            cnt+=f(idx+1,10,newtight,newlz,s,k);
        }
        else if(prev==10||abs(prev-dig)<=k){
            cnt+=f(idx+1,dig,newtight,newlz,s,k);
        }
    }
    return dp[idx][prev][tight][lz]=cnt;
}


ll solve(ll n){
    string s= to_string(n);
    memset(dp,-1,sizeof(dp));
    return f(0,10,1,1,s,k);
}
    long long goodIntegers(long long l, long long r, int k) {
    this->k = k;
        return solve(r)-solve(l-1);        
    }
};