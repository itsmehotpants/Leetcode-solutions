class Solution {
public:
    using ll =long long;
    vector<long long> minTimeMaxPower(int n, vector<vector<int>>& edges, int power, vector<int>& cost, int src, int tar) {
        vector<vector<pair<int,int>>>adj(n);
        for(auto&e:edges) adj[e[0]].push_back({e[1],e[2]});

        const ll INF=1e18;
        vector<vector<ll>>dist(n,vector<ll>(power+1,INF));
        priority_queue<tuple<ll,int,int>,vector<tuple<ll,int,int>>,greater<>> pq;
        dist[src][power]=0;
        pq.push({0,src,power});

        while(!pq.empty()){
            auto [t,u,p]=pq.top();
            pq.pop();
            if(t>dist[u][p]) continue;
            if(p>=cost[u]){
                for(auto [v,w]:adj[u]){
                    if(t+w<dist[v][p-cost[u]]){
                        pq.push({dist[v][p-cost[u]]=t+w,v,p-cost[u]});
                    }
                }
            }
        }
        ll mn =INF;
        int mp=-1;
        for(int p = 0;p<=power;p++){
            if(dist[tar][p]<mn|| (dist[tar][p]==mn &&p>mp)){
                mn =dist[tar][p];
                mp=p;
            }
            
        }
        return mn==INF?vector<ll>{-1,-1}:vector<ll>{mn,mp};
    }
};