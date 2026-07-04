class Solution {
public:
    int minScore(int n, vector<vector<int>>& r) {
       vector<vector<pair<int,int>>>adj(n+1);

    for(auto &e:r){
        adj[e[0]].push_back({e[1],e[2]});
        adj[e[1]].push_back({e[0],e[2]});
    }
    vector<int>vis(n+1,0);
    queue<int>q;
    q.push(1);
    int ans = INT_MAX;
    while(!q.empty()){
        int t = q.front();
        q.pop();
        
        for(auto &[nei,wt]:adj[t]){
            ans= min(ans,wt);
            if(!vis[nei]){
                vis[nei]=1;
                q.push(nei);
            }
        }
    }
return ans;

    }
};