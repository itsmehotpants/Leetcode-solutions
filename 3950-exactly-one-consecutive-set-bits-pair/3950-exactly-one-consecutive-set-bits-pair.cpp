class Solution {
public:
    bool consecutiveSetBits(int n) {
        int ans=0;
        while(n){
            ans+=(n&3) ==3;
            n>>=1;
        }
        return ans==1;
    }
};