class Solution {
public:
    vector<int>dr = {1,-1,0,0};
    vector<int>dc= {0,0,1,-1};
    void bfs(vector<vector<int>>& grid, vector<vector<int>>&score,int n){
        queue<pair<int,int>>q;
        for(int i =0;i<n;i++){
            for(int j =0;j<n;j++){
                if(grid[i][j]==1){
                    score[i][j]=0;
                    q.push({i,j});
                }
            }
        }
        while(!q.empty()){
            auto t =q.front();q.pop();
            int x= t.first,y=t.second;
            int s =score[x][y];

            for(int i = 0;i<4;i++){
                int nx =x+dr[i],ny=y+dc[i];

                if(nx>=0&&nx<n&&ny>=0&&ny<n&&score[nx][ny]>1+s){
                    score[nx][ny]=1+s;
                    q.push({nx,ny});
                }
            }
        }
    }

    int maximumSafenessFactor(vector<vector<int>>& grid) {
       int n  =grid.size();
       if(grid[0][0]==1 || grid[n-1][n-1]==1) return 0;
       vector<vector<int>>vis(n,vector<int>(n,false));
       vector<vector<int>>score(n,vector<int>(n,INT_MAX));
       bfs(grid,score,n); 

       priority_queue<pair<int,pair<int,int>>>pq;
       pq.push({score[0][0],{0,0}});

       while(!pq.empty()){
        auto safe= pq.top().first;
        auto temp = pq.top().second;
        pq.pop();

        if(temp.first==n-1 && temp.second==n-1) return safe;
        vis[temp.first][temp.second]=true;

        for(int i =0;i<4;i++){
            int nx= temp.first+dr[i];
            int ny= temp.second +dc[i];

             if(nx>=0&&nx<n&&ny>=0&&ny<n&&vis[nx][ny]==0){
                    vis[nx][ny]=1;
                    int s = min(safe,score[nx][ny]);
                    pq.push({s,{nx,ny}});
                }
        }
       }
       return -1;
    }
};