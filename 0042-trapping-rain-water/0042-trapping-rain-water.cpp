class Solution {
public:
    int trap(vector<int>& h) {
        int n = h.size();
        int total = 0;
        vector<int>maxL(n),maxR(n);
        maxL[0]=h[0],maxR[n-1]=h[n-1];
        for (int j = 1; j <n; j++) {
                maxL[j] = max(maxL[j-1], h[j]);
            }

            for (int j = n-2; j>=0; j--) {
                maxR[j] = max(maxR[j+1], h[j]);
            }

        for (int i = 0; i < n; i++) {
            

            int cap = min(maxL[i], maxR[i]);
            total += max(0, cap - h[i]);
        }

        return total;
    }
};