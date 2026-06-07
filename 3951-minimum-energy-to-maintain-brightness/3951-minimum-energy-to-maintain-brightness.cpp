class Solution {
public:
    using ll =long long;
    long long minEnergy(int n, int brt, vector<vector<int>>& ivl) {
        sort(ivl.begin(),ivl.end());
        ll t=0,l=ivl[0][0],r=ivl[0][1];
        for(int i =1;i<ivl.size();i++){
            if(ivl[i][0]<=r+1){
                r= max(r,(ll)ivl[i][1]);
            }
            else{
                t+=r-l+1;
                l=ivl[i][0],r=ivl[i][1];
            }
            // t+=r-l+1;;
        }
        t+=r-l+1;
        return 1LL*((brt+2)/3)*t;
    }
};