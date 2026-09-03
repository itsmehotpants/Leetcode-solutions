class Solution {
public:
    vector<int> findOrder(int n, vector<vector<int>>& pre) {
        vector<int>indeg(n,0);
        vector<vector<int>>adj(n);
        for(auto&e:pre){
            adj[e[0]].push_back(e[1]);
        }
        for(int i=0;i<n;i++){
            for(int x:adj[i]){
                indeg[x]++;
            }
        }
        queue<int>q;
        for(int i=0;i<n;i++){
            if(indeg[i]==0) q.push(i);
        }
        vector<int>ans;

        while(!q.empty()){
            int node=q.front();q.pop();
            ans.push_back(node);
            for(auto it:adj[node]){
                indeg[it]--;
                if(indeg[it]==0) q.push(it);
            }
        }
        if(ans.size()!=n) return{};
        reverse(ans.begin(),ans.end());
        return ans;
    }
};