class Solution {
public:
    bool checkGoodInteger(int n) {
        int s= 0,sq=0;
        while(n){
            int dig= n%10;
            s+=dig;
            sq+=dig*dig;
            n/=10;
        }
        return sq-s>=50;
    }
};