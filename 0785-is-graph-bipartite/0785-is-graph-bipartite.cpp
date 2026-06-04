class Solution {
public:

    bool dfs(int node,vector<vector<int>>& graph,vector<int> &color){
        for(int i:graph[node]){
            if(color[i]==-1) {
               color[i]=1-color[node];
                if(dfs(i,graph,color)==false) return false;
            }
            else if(color[i]==color[node]) return false;
        }
        return true;
    }

    bool isBipartite(vector<vector<int>>& graph) {

        int n = graph.size();
        //color[0]=0;

        vector<int> color(n, -1);
        for(int i =0;i<n;i++){
            if(color[i]==-1) {
            color[i]=0;
            if(dfs( i,graph,color)==false) return false;
            }

        }
        return true;
    }
};