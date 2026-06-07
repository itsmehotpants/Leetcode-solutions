class Solution {
public:
    using ll =long long;
    int sumOfGoodIntegers(int n, int k) {
      ll  res=0;
        for(ll x =max(1,n-k);x<= (ll)n+k;x++){
            if((n&x)==0)
            res+=x;
        }
        return res;
    }
};