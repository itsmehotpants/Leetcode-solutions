class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
     int n= points.size();
     vector<vector<pair<int,int>>> adj(n);

for(int i=0;i<n;i++){

    for(int j=i+1;j<n;j++){

        int wt =
            abs(points[i][0]-points[j][0]) +
            abs(points[i][1]-points[j][1]);

        adj[i].push_back({j,wt});
        adj[j].push_back({i,wt});
    }
}
     vector<int>vis(n,0);
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    int sum=0;
    pq.push({0,0});
    while(!pq.empty()){
        auto[wt,node]=pq.top();pq.pop();
        if(vis[node]) continue;
        vis[node]=1;
        sum+=wt;
        for(auto [nbr,edgewt]:adj[node]){
            if(!vis[nbr]) pq.push({edgewt,nbr});
        }
    }
    return sum;
    }
};