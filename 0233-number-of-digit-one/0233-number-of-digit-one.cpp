class Solution {
public:
int dp[10][2][10];

int solve(string &s,int idx,int tight, int cnt){
    if(idx>=s.size()) return cnt;
    if(dp[idx][tight][cnt]!=-1) return dp[idx][tight][cnt];
    int limit = (tight==1?s[idx]-'0':9);
    int ans =0;
    for(int digit =0;digit<=limit;digit++){
        int newtight = tight &&(digit==limit);
        ans+=solve(s,idx+1,newtight,cnt+(digit==1));
    }
    return dp[idx][tight][cnt]=ans;

}
    int countDigitOne(int n) {
        memset(dp,-1,sizeof(dp));
        int l=0,r=1;
        string ri = to_string(n);
        int ans = solve(ri,0,1,0);
        return ans;

        
    }
};