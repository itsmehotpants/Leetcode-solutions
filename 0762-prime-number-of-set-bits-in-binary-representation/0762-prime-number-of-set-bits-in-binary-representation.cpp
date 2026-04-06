class Solution {
public:

bool is_prime(int n){
    if(n==2) return true;
    if(n==1||n==0) return false; 
    for(int i =2;i*i<=n;i++){
        if(n%i==0) return false;
    }
    return true;
}
    int countPrimeSetBits(int left, int right) {
        int ans=0;
        for(int j =left;j<=right;j++){
            if(is_prime(__builtin_popcount(j))) ans++;
        }
        return ans;
    }
};