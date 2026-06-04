class Solution {
public:

// void bfs(int node,int n,int m,vector<vector<int>>&grid,vector<int>&vis){

// }

    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size(),m=grid[0].size();
       // vector<int>vis(n,0);
        queue<pair<int,int>>q;
        int time=0;
        int fresh=0;
        for(int i =0;i<n;i++){
            for(int j =0;j<m;j++){
                if(grid[i][j]==2) q.push({i,j});
                if(grid[i][j]==1) fresh++;
                            }
        }
        if(fresh==0) return 0;

vector<pair<int,int>> dir = {{1,0},{-1,0},{0,1},{0,-1}};

        while(!q.empty() &&fresh>0){
            int sz=q.size();
            for(int  i=0;i<sz;i++){
                int row =q.front().first;
                int col =q.front().second;
                q.pop();

                for(auto [dr,dc]:dir){
                    int r= row+dr;
                    int c= col+dc;
                    if(r>=0&&c>=0&&r<n&&c<m&&grid[r][c]==1){
                        grid[r][c]=2;
                        fresh--;
                        q.push({r,c});
                    }
                }
            }
            time++;
        }
        return fresh==0? time:-1;

    }
};