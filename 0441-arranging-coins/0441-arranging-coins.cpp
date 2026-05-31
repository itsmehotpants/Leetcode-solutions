class Solution {
public:
    int arrangeCoins(int n) {
        long long num = n;
        return (int)(sqrt(8*num+1)-1)/2 ;
    }
};