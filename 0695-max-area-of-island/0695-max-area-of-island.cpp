class Solution {
public:

vector<pair<int,int>>dir=  {{1,0},{0,1},{-1,0},{0,-1}};
int m,n;
int dfs(int i,int j,vector<vector<int>>& grid){
   if(i<0||j<0||i>=m||j>=n||grid[i][j]==0) return 0;
int size=1;
    grid[i][j]=0;
    for(auto [u,v]:dir){
      size+=  dfs(i+u,j+v,grid);
    }
    return size;

    }

int maxAreaOfIsland(vector<vector<int>>& grid) {
        m =grid.size(),n=grid[0].size();
        int ans= 0;
        for(int i=0;i<m;i++){
            for(int j =0;j<n;j++){
                if(grid[i][j]==1){
                    ans = max(ans,dfs(i,j,grid));
                }
            }
        }
        return ans;
    }
};