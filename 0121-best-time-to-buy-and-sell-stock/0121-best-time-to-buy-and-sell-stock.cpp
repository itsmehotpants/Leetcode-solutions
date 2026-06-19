class Solution {
public:
    int maxProfit(vector<int>& p) {
        int n = p.size();
        int buy = INT_MAX;
        int prof = 0;
        for(int i=0; i<n; i++){
            buy = min(buy, p[i]);
            prof = max(prof, p[i] - buy); 
        }
        return prof;
    }
};