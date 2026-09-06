class Solution {
public:
    int countGroups(vector<int>& pos, vector<int>& s, int distance) {
        int n = pos.size();
        int grps = 1;
        int nxts = s[n-1];
        for(int i = n-2 ; i >= 0 ; i--){
            if(pos[i+1]-pos[i]<=distance || s[i]>nxts){
                continue;
            }
            nxts = s[i];
            grps++;
            
        }
        return grps;
    }
};