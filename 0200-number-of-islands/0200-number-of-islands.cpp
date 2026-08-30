class Solution {
public:

vector<pair<int,int>>dir={{1,0},{0,1},{-1,0},{0,-1}};
int m,n;
void bfs(int i,int j,vector<vector<char>>& grid){
    queue<pair<int,int>>q;
    q.push({i,j});
    grid[i][j]='0';
    while(!q.empty()){
        auto[x,y] = q.front();q.pop();
        for(int k =0;k<4;k++){
            int nx=  x+dir[k].first;
            int ny=  y+dir[k].second;
        
        if(nx>=0 &&ny>=0&&nx<m&&ny<n&&grid[nx][ny]=='1'){
            grid[nx][ny]='0';
            q.push({nx,ny});
        }
        }
    }
}

void dfs(int i,int j,vector<vector<char>>& grid){
   if(i<0||j<0||i>=m||j>=n||grid[i][j]=='0') return;

    grid[i][j]='0';
    for(auto [u,v]:dir){
        dfs(i+u,j+v,grid);
    }

    }



    int numIslands(vector<vector<char>>& grid) {
        m=grid.size(),n=grid[0].size();
        int ans=0;
        for(int i =0;i<m;i++){
            for(int j =0;j<n;j++){
                if(grid[i][j]=='1'){
                    ans++;
                    dfs(i,j,grid);
                }
            }
        }
        return ans;
    }
};