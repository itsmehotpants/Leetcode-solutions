class Solution {
public:
        long long minOperations(vector<int>& A) {
        long long res = 0;
        for (int i = 0; i + 1 < A.size(); i++) {
            res += max(0, A[i] - A[i + 1]);
        }
        return res;
    
    }
};