class Solution {
public:
    vector<int> findOrder(int V, vector<vector<int>>& pre) {
         vector<vector<int>>adj(V);
        for(const auto &e:pre){
            adj[e[0]].push_back(e[1]);
        }
        
        vector<int>indegree(V,0);
        for(int i =0;i<V;i++){
            for(int x:adj[i]){
                indegree[x]++;
            }
        }
        queue<int>q;
        for(int i=0;i<V;i++){
            if(indegree[i]==0) q.push(i);
        }
                vector<int>ans;

        while(!q.empty()){
            int node=q.front();
            q.pop();
            ans.push_back(node);
            for(int nbr:adj[node]){
                indegree[nbr]--;
                if(indegree[nbr]==0) q.push(nbr);
            }
        }
        if (ans.size() != V)
            return {};
        reverse(ans.begin(),ans.end());
        return ans;
    }
};