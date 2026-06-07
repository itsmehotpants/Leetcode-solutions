class Solution {
public:
    vector<string>ans;
    string s;
    int n,k;
    void dfs(int i , int cost){
        if(cost>k) return;
        if(i==n){
            ans.push_back(s);
            return;
        }
        dfs(i+1,cost);
        if(i==0||s[i-1]=='0'){
            s[i]='1';
            dfs(i+1,cost+i);
            s[i]='0';
        }
    }
    vector<string> generateValidStrings(int N, int K) {
        n = N;k=K;
        s=string(n,'0');
        dfs(0,0);
        return ans;
    }
};