class Solution {
public:
// int dist[75][75][4][75] //r,c,dist,turns;
    int minCost(vector<vector<int>>& grid, int k) {
       int m =grid.size(),n=grid[0].size();
       if(m==1&&n==1) return grid[0][0];

    vector<vector<vector<vector<int>>>>cost(m,vector<vector<vector<int>>>(n,vector<vector<int>>(5,vector<int>(k+1,INT_MAX))));

    priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>>q;

    q.push({grid[0][0],0,0,0,0});
    cost[0][0][0][0]=grid[0][0];

vector<int> dx = {0,0,-1,1};
        vector<int> dy = {1,-1,0,0};
    while(!q.empty()){
        vector<int>val = q.top();
        q.pop();
        int c = val[0];
            int x = val[1];
            int y = val[2];
            int d = val[3];
            int t = val[4];

        if(cost[x][y][d][t]!=c) continue;
        for(int j = 0;j<4;j++){
            int nx=x+dx[j],ny=y+dy[j];
            int nc = t;
            if(nx<0||ny<0||nx>=m||ny>=n) continue;

            if(d!=0 && d!=j+1) nc++;
            if(nc>k) continue;

            int costed = c+grid[nx][ny];
            if(cost[nx][ny][j+1][nc]<=costed) continue;

            cost[nx][ny][j+1][nc]=costed;
            q.push({costed,nx,ny,j+1,nc});
        }    
    }

        int ans = INT_MAX;
        for(int i=0;i<5;i++){
            for(int j=0;j<=k;j++){
                ans = min(ans,cost[m-1][n-1][i][j]);
            }
        }
        return ans==INT_MAX ? -1 : ans; 
    }
};