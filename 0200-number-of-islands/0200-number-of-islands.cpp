class Solution {
public:
vector<pair<int,int>>dir={{1,0},{0,1},{-1,0},{0,-1}};
void bfs(int n,int m,vector<vector<char>>& grid){

    queue<pair<int,int>> q;

    q.push({n,m});
    grid[n][m]='0';

    while(!q.empty()){

        auto [i,j]=q.front();
        q.pop();

        for(auto [dx,dy]:dir){

            int x=i+dx;
            int y=j+dy;

            if(x<0 || y<0 || x>=grid.size() || y>=grid[0].size())
                continue;

            if(grid[x][y]=='1'){

                grid[x][y]='0';

                q.push({x,y});
            }
        }
    }
}

    int numIslands(vector<vector<char>>& grid) {
        int n =grid.size(),m=grid[0].size();
        int ans=0;
        for(int i =0;i<n;i++){
            for(int j =0;j<m;j++){
                if(grid[i][j]=='1'){
                    ans++;
                    bfs(i,j,grid);
                }
            }
            
        }
        return ans;

    }
};