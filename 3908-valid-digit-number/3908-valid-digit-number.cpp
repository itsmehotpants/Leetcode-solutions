class Solution {
public:
    bool validDigit(int n, int x) {
        bool ans=false;
        while(n){
            if(n/10==0){
                if(n==x) return false;
            }
            if(n%10==x) ans=true;
            n/=10;
        }
        return ans;
    }
};