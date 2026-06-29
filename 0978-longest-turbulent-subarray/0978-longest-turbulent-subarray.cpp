class Solution {
public:
vector<vector<int>>dp;
    int maxTurbulenceSize(vector<int>& arr) {
        int n =arr.size();
        dp.assign(n,vector<int>(2,-1));

        int maxlen=1;
        for(int i =0;i<n;i++){
            maxlen =max(maxlen,dfs(i,true,arr));
            maxlen =max(maxlen,dfs(i,false,arr));
        }
        return maxlen;
    }
    int dfs(int i,bool sign, vector<int>&arr){
        int signIdx = sign?1:0;
        if(i==arr.size()-1) return 1;
        if(dp[i][signIdx]!=-1) return dp[i][signIdx];
 int res = 1;
        if ((sign && arr[i] > arr[i + 1]) ||
            (!sign && arr[i] < arr[i + 1])) {
            res = 1 + dfs(i + 1, !sign, arr);
        }
        return dp[i][signIdx] =res;
    }
};