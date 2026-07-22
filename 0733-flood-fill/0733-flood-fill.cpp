class Solution {
public:
int n,m;
vector<pair<int,int>>dir= {{1,0},{0,1},{-1,0},{0,-1}};

void dfs(vector<vector<int>>& a, int i, int j, int col,int val){
    if(i<0||j<0||i>=n||j>=m||a[i][j]==col||a[i][j]!=val) return;
    a[i][j]=col;
    for(auto &[u,v]:dir){
        dfs(a,i+u,j+v,col,val);
    }

}

    vector<vector<int>> floodFill(vector<vector<int>>& a, int sr, int sc, int col) {
        n = a.size();m=a[0].size();
        int val =a[sr][sc];
        dfs(a,sr,sc,col,val);
        return a;
    }
};