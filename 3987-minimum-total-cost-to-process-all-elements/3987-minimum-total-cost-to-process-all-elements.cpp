class Solution {
public:
typedef  long long ll;
    
    int minimumCost(vector<int>& nums, int k) {
        ll mod =1e9+7,res=k,cnt=0,cost=0;
        for(int i:nums){
            if(res<i){
          ll req = (i-res+k-1)/k;
                __int128 sum = (__int128)(cnt*2 +req+1)*req/2 %mod;
            cost = (cost+ (ll)sum)%mod;
            cnt+=req;
            res+=req*k;
        }
            res-=i;
        }
        return cost;
        
    }
};