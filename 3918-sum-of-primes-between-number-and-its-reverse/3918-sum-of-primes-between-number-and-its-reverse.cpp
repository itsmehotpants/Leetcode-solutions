class Solution {
public:
    bool isprime(int n ){
        if(n<2) return 0;
        for(int i =2;i*i<=n;i++){
            if(n%i==0) return 0;
        }
        return 1;
    }
    int sumOfPrimesInRange(int n) {
        int r=0;
    for(int x=n;x;x/=10){
        r=r*10+x%10;
        
    }   
        int res=0;
        for(int i =min(n,r);i<=max(n,r);i++){
            if(isprime(i)) res+=i;
        }
        return res;
    }
};