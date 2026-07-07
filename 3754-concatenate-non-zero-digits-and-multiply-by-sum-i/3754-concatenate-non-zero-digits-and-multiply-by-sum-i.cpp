class Solution {
public:
    long long sumAndMultiply(int n) {
        using ll = long long;
       ll x = 0;
        ll sum = 0;
        int i = 0;
        while (n > 0) {
            int rem = n%10;
            if (rem != 0){
                sum += rem;
                x += (pow(10,i)*rem);
                i++;
            }
            n = n/10;
        }
        return sum*x;
    }
};