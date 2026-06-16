class Solution {
public:

void solve(string& s ,int i, vector<string>&part,vector<vector<bool>>&t,vector<vector<string>>&res){
if(i==s.length()) {
    res.push_back(part);
return;
}
for(int j = 0;j<s.length();j++){
    if(t[i][j]==1){
        part.push_back(s.substr(i,j-i+1));
        solve(s,j+1,part,t,res);
        part.pop_back();
    }
}

}
    vector<vector<string>> partition(string s) {
        int n =s.length();
        vector<vector<bool>> t(n,vector<bool>(n,false));
        for(int i =0;i<n;i++) t[i][i]=true;
        for(int  l=2;l<=n;l++){
            for(int  i =0;i+l-1<n;i++){
                int j =i+l-1;
                if(s[i]==s[j]){
                    if(l==2) t[i][j]=true;
                    else t[i][j]=t[i+1][j-1];
                }
            }
        }


    vector<vector<string>>res;
    vector<string>partition;
    solve(s,0,partition,t,res);
    return res;
//solve(s,0,)

    }
};