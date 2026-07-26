class Solution {
public:
    using ll =long long;
    long long minCost(int m, int n, vector<vector<int>>& p) {

        auto id = [&](int x,int y){
            return x*n+y;
        };
        vector<vector<ll>> dist(2,vector<ll>(m*n,LLONG_MAX));
        int dx[4] = {-1,1,0,0},dy[4]={0,0,-1,1};
        priority_queue<tuple<ll,int,int>,vector<tuple<ll,int,int>>,greater<tuple<ll,int,int>>>pq;

        dist[1][0] = 1;
        pq.push({1,0,1}); //d,u,parity


        while(!pq.empty()){
            auto[d,u,parity]=pq.top();
            pq.pop();

            if(d!=dist[parity][u]) continue;
            int x = u/n,y = u%n;
            if(d+p[x][y]<dist[parity^1][u]){
                dist[parity^1][u] = d+p[x][y];
                pq.push({dist[parity^1][u],u,parity^1});
            }

            for(int k =0;k<4;k++){
                int nx = x+dx[k],ny =y+dy[k];

                if(nx<0|| nx>=m||ny<0||ny>=n) continue;

                ll cost = 1LL*(nx+1)*(ny+1);
                bool ok;
                if(parity){
                    ok = (dx[k]==1 && dy[k]==0)||(dx[k]==0 && dy[k]==1);
                }
                else{
                     ok = (dx[k]==-1 && dy[k]==0)||(dx[k]==0 && dy[k]==-1);
                    
                }
                if(!ok) cost+=p[x][y];
                int v =id(nx,ny);

                if(d+cost<dist[parity^1][v]){
                    dist[parity^1][v]=d+cost;
                    pq.push({ dist[parity^1][v],v,parity^1});
                }
                }
            }
       
    
 int target  = id(m-1,n-1);
    
    return min(dist[0][target],dist[1][target]);
    
    }
};