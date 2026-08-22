class Solution {
public:
    bool checkDivisibility(int n) {
        int sum=0,prod=1,x=n;
        while(x){
            int a = x%10;
            sum+=a;
            prod*=a;
            x/=10;
        }
        return n%(sum+prod)==0;
    }
};