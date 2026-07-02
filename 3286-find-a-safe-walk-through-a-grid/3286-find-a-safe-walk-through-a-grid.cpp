class Solution {
public:

typedef tuple<int,int,int> iii;
    bool findSafeWalk(vector<vector<int>>& g, int health) {
        int  m =g.size(),n=g[0].size();

        priority_queue<iii,vector<iii>,greater<iii>>pq;
        pq.push({g[0][0],0,0});

        vector<vector<int>>dist(m,vector<int>(n,INT_MAX));
        int dx[] = {1,-1,0,0},dy[] = {0,0,1,-1};
        dist[0][0]=g[0][0];

        while(!pq.empty()){
            auto [curr,x,y] = pq.top();
            pq.pop();
        if(curr>dist[x][y]) continue;
            for(int i =0;i<4;i++){
                int nx= x+dx[i];
                int ny= y+dy[i];

                if(nx<0||ny<0||nx>=m||ny>=n) continue;
                if(curr+g[nx][ny]<dist[nx][ny]){
                    dist[nx][ny]= curr+g[nx][ny];
                    pq.push({dist[nx][ny],nx,ny});
                }
            }
        }
        return dist[m-1][n-1]<health;
    }
};