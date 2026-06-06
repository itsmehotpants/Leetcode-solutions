class Solution {
public:
int timer=1;
void dfs(int node,int parent,vector<int>&vis,vector<vector<int>>&adj,vector<int>&low,vector<int>&tin,vector<vector<int>>&bridges){
    vis[node]=1;
    tin[node]=low[node]=timer;
    timer++;
    for(auto it:adj[node]){
        if(it==parent) continue;
        if(!vis[it]){
            dfs(it,node,vis,adj,low,tin,bridges);
            low[node]= min(low[node],low[it]);
            if(low[it]>tin[node]){
                    bridges.push_back({it,node});
            }
        }
        else{
            low[node]= min(low[node],low[it]);
        }
    }
}
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& conn) {
        vector<vector<int>>adj(n);
        for(auto &e:conn){
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        vector<int>vis(n,0);
        vector<int> tin(n),low(n);
        vector<vector<int>>bridges;
        dfs(0,-1,vis,adj,low,tin,bridges);
        return bridges;
    }
};