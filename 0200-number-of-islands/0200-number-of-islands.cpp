class Solution {
public:
vector<pair<int,int>>dir={{1,0},{0,1},{-1,0},{0,-1}};
void dfs(int n,int m,vector<vector<char>>&grid){
    if(n<0||m<0||n>=grid.size()||m>=grid[0].size()) return;
    if(grid[n][m]!='1') return;

        grid[n][m]='0';
    for(auto [u,v]:dir){
        dfs(n+u,m+v,grid);
    }
}

    int numIslands(vector<vector<char>>& grid) {
        int n =grid.size(),m=grid[0].size();
        int ans=0;
        for(int i =0;i<n;i++){
            for(int j =0;j<m;j++){
                if(grid[i][j]=='1'){
                    ans++;
                    dfs(i,j,grid);
                }
            }
            
        }
        return ans;

    }
};