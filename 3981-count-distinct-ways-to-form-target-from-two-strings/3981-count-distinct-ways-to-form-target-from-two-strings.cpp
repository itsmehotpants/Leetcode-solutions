class Solution {
public:
    int dp[101][101][101][4];
    const int mod =1e9 + 7;
    vector<int>pos1[26];
    vector<int>pos2[26];
    int dfs(int i,int j ,int k,int mask,string &tar){
        if(i==tar.size()) return mask==3;
        if(dp[i][j][k][mask]!=-1) return dp[i][j][k][mask];
        char c= tar[i];
        long long res=0;
        
        auto &v =pos1[c-'a'];
        auto it = upper_bound(v.begin(),v.end(),j-1);
        for(;it!=v.end();it++){
            int idx = *it;
            res = res+dfs(i+1,idx+1,k,mask|1 , tar);
            res= res%mod;
        }

        auto &v2 =pos2[c-'a'];
        auto it2 = upper_bound(v2.begin(),v2.end(),k-1);
        for(;it2!=v2.end();it2++){
            int idx = *it2;
            res = res+dfs(i+1,j,idx+1,mask|2 , tar);
            res= res%mod;
        }
        return  dp[i][j][k][mask]=(int)res;
        
    }
    
    int interleaveCharacters(string w1, string w2, string tar) {
        
        int n1=w1.size(),n2=w2.size(),n3=tar.size();
        

        for(int i =0;i<n1;i++){
            pos1[w1[i]-'a'].push_back(i);
        }

         for(int i =0;i<n2;i++){
            pos2[w2[i]-'a'].push_back(i);
        }
        memset(dp,-1,sizeof(dp));
        return dfs(0,0,0,0,tar);
        

        
    }
};