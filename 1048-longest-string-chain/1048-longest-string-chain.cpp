class Solution {
public:
int n;
int dp[1001];
bool isPred(string& a,string& b){
    int m =a.length(),n=b.length();
    if(n-m !=1) return false;

int i=0,j=0;
while(i<m && j<n){
    if(a[i]==b[j]) i++;
    j++;
}
return i==m;
} 

static bool comp(string &a,string& b){
     return a.length()<b.length();
}
int lis(vector<string>& words,int prev,int curr){
    if(curr>=n) return 0;
    int taken=0,not_taken=0;
    if(dp[prev+1]!=-1) return dp[prev+1];
    if(prev==-1 || isPred(words[prev],words[curr])){
        taken =1+lis(words,curr,curr+1);
    }
    not_taken =lis(words,prev,curr+1);
return dp[prev+1]= max(taken, not_taken);
}
    int longestStrChain(vector<string>& words) {
    //    memset(dp,-1,sizeof(dp));
      n= words.size();
        sort(words.begin(),words.end(),comp);
        vector<int> dp2(n,1);
        int ans=1;
    //   return  lis(words,-1,0);
    for(int i =0;i<n;i++){
        for(int j=0;j<i;j++){
            if(isPred(words[j],words[i])){
            dp2[i] = max(dp2[i],dp2[j]+1);
            ans = max(ans,dp2[i]);
        }
    }}
    return ans;
    }
};