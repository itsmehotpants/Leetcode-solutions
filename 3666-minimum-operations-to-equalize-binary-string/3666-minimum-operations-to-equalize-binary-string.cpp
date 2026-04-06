class Solution {
public:
    int minOperations(string s, int k) {
        long long z = 0 ;
        for (auto & x: s) if (x == '0') ++z ;
        long long n =  s.length(), o = n - z ;
        int ans = -1 ;
        if (z == 0) return 0 ;
        for (long long i = 1 ; i <= n ; ++i) {
            long long p = i * (long long)k ;
            if ((p - z) & 1) continue ;
            if (i & 1) {
                if (p >= z && p <= (z * i + o * (i - 1)))  return (int)i ;
            } else {
                if (p >= z && p <= (z * (i - 1) + o * i)) return (int)i ;
            }
        }
        return ans ;
    }
};