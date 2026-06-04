class Solution {
public:

bool dfs(int node , vector<vector<int>>&adj,vector<bool>&vis,vector<bool>&path){
    vis[node]=1,path[node]=1;

    for(int i:adj[node]){
        if(!vis[i]){
            if(dfs(i,adj,vis,path)) return true;;
        }
        else if(path[i]==1) return true;
    }
    path[node]=false;
    return false;
}
    bool canFinish(int n, vector<vector<int>>& pre) {
        vector<vector<int>>adj(n);
        for(const auto &e:pre){
            int u =e[0],v=e[1];
            adj[u].push_back(v);
        }
        vector<bool>vis(n,0);
        vector<bool>path(n,0);
        for(int i =0;i<n;i++){
            if(!vis[i]){
                if(dfs(i,adj,vis,path)) return false;
            }
        }
        return true;
    }
};