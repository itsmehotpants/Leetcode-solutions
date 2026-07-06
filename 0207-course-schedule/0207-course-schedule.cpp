class Solution {
public:

bool dfs(int node,vector<vector<int>>&adj,vector<int>&vis,vector<int>&path){
vis[node]=1,path[node]=1;
for(int i:adj[node]){
    if(!vis[i]){
        if(dfs(i,adj,vis,path)) return true;

    }
    else if(path[i]==1) return true;
}
path[node]=false;
return false;

    }

    bool canFinish(int n, vector<vector<int>>& preq) {
        vector<vector<int>>adj(n);
        for(auto &e:preq){
            adj[e[0]].push_back(e[1]);
        }   
        vector<int>vis(n,0); 
        vector<int>path(n,0);
        for(int i =0;i<n;i++){
            if(!vis[i]){
               if(dfs(i,adj,vis,path)) return false;
            }
        } 
        return true;   

    }
};