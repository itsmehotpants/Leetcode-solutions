class Solution {
public:
const int mod =1e9 +7;
using ll = long long;
ll kadane(vector<ll>&a){
    ll cur=a[0],maxm=a[0];
    for(int i =1;i<a.size();i++){
        cur=max(a[i],cur+a[i]);
        maxm = max(maxm,cur);
    }
    return maxm;
}

vector<int>getDivisors(int x){
    vector<int>d;
    for(int i = 1;i*i<=x;i++){
        if(x%i==0) {
            d.push_back(i);
            if(i*i!=x) d.push_back(x/i);
    }
    }
    return d;
}


    int divisibleGame(vector<int>& nums) {
        int n =nums.size();
        unordered_set<int>cand;
        for(int x:nums){
            auto d= getDivisors(x);
            for(int i:d){
                if(i>1) cand.insert(i);
            }
        }
        ll best_score = LLONG_MIN;
        int bestK=2;
        bool found =0;
        vector<ll>arr(n);
        for(int k:cand){
            for(int i=0;i<n;i++){
                if(nums[i]%k==0) {
                    arr[i]=nums[i];
            }
            else{
                arr[i]=-nums[i];
            }
            }
            found=1;
            ll score =kadane(arr);
            if(score>best_score ||(score==best_score && k<bestK)){
                best_score=score;
                bestK=k;
            }
        }
        if(!found){
            best_score=-nums[0];
            bestK=2;
        }
        ll score = ((best_score % mod) + mod) % mod;
        ll ans = (1LL * bestK * score) % mod;
        return (int)ans;

        }
};
