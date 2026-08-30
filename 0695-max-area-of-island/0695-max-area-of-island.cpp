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

   int bfs(int i,int j,vector<vector<int>>& grid){
    int ans = 0;

    queue<pair<int,int>> q;
    q.push({i,j});
    grid[i][j] = 0;

    while(!q.empty()){
        auto [x,y] = q.front();
        q.pop();

        ans++;

        for(int k = 0; k < 4; k++){
            int nx = x + dir[k].first;
            int ny = y + dir[k].second;

            if(nx >= 0 && ny >= 0 &&
               nx < m && ny < n &&
               grid[nx][ny] == 1){

                grid[nx][ny] = 0;
                q.push({nx,ny});
            }
        }
    }

    return ans;
}

int maxAreaOfIsland(vector<vector<int>>& grid) {
        m =grid.size(),n=grid[0].size();
        int ans= 0;
        for(int i=0;i<m;i++){
            for(int j =0;j<n;j++){
                if(grid[i][j]==1){
                    ans = max(ans,bfs(i,j,grid));
                }
            }
        }
        return ans;
    }
};