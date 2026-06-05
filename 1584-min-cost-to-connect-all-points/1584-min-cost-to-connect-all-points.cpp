class Solution {
public:
    //everything is exactly same as in basic prims algo ..only thing is to make adjacency list optimally
    int manhattDist(vector<int>&v1 , vector<int>&v2)
    {
        return abs(abs(v1[0]-v2[0]) + abs(v1[1]-v2[1]));
    }
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        vector<pair<int,int>> adj[n]; //{point , cost or Manhattan dist}

        //we have to make a adjacency list fom every point to every other point
        for(int i=0; i<n ; i++)
        {
            for(int j=i+1;j<n ; j++)
            {
                adj[i].push_back({j , manhattDist(points[i] , points[j])});
                adj[j].push_back({i , manhattDist(points[i] , points[j])});
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