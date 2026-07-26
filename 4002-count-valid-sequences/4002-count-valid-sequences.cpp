class Solution {
public:
using ll= long long;
    const int mod =1e9+7;
    ll power(ll a,ll b){
        ll ans=1;
        while(b){
            if(b&1) ans  = ans*a%mod;
            a = a*a%mod;
            b>>=1;
        }
        return ans;
    }
    int countValidSequences(int n, int k) {
        vector<ll> fact(n+1),inv(n+1);

        fact[0]=1;
        for(int i =1;i<=n;i++){
            fact[i] = fact[i-1]*i%mod;
        }
        inv[n]=power(fact[n],mod-2);

        for(int i =n;i>=1;i--){
            inv[i-1]=inv[i]*i%mod;
        }

        auto C = [&](int n,int r)->ll
        {
            if(r<0||r>n) return 0;
            return fact[n]*inv[r]%mod*inv[n-r]%mod;
        };

        ll total = C(n-1,k-1);
        ll odd = 0;
        if((n-k)%2==0){
            int N = (n+k-2)/2;
            odd = C(N,k-1);
        }
        return (total-odd+mod)%mod;
    }
};