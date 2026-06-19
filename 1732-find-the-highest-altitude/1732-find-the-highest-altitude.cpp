class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int maxm=gain[0];
        int alt =gain[0];
        for(int i =1;i<gain.size();i++){
            alt+=gain[i];
            maxm = max(maxm,alt);
        }
        return maxm>0?maxm:0;
    }
};