// class Solution {
// public:

// vector<vector<int>>G;
// vector<bool>seen;
// int dfs(int i){
//     seen[i]=true;
//     int H=1;
//     for(auto adj:G[i]){
//         if(!seen[adj]){
//             H=max(H,1+dfs(adj));
//         }
//     }
//         seen[i]=false;

//             return H;

// }
//     vector<int> findMinHeightTrees(int n, vector<vector<int>>& E) {
//         G.resize(n);
//         seen.resize(n);
//         vector<int>ans;
//         for(auto &e:E){
//             G[e[0]].push_back(e[1]);
//             G[e[1]].push_back(e[0]);
//         }

//         for(int i=0,minH=n;i<n;i++){
//             int H=dfs(i);
//             if(H<minH){
//                 minH=H;
//                 ans.clear();
//             }
//             if(H==minH) ans.push_back(i);
//         }
//         return ans;
//     }
// };



class Solution{
    public:

    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {

        if(n==1) return {0};

        vector<vector<int>>adj(n);
        vector<int>deg(n,0);
        vector<int>ans;

        for(auto it:edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);

            deg[it[0]]++;
            deg[it[1]]++;
        }

        queue<int>q;
        for(int i=0;i<n;i++){
            if(deg[i]==1){
                q.push(i);
            }
        }

        int nodes=n;
        while(nodes>2){
            int sz=q.size();
            nodes-=sz;

            for(int i=0;i<sz;i++){
                int curr=q.front();q.pop();

                for(auto it:adj[curr]){
                    deg[it]--;
                    if(deg[it]==1) q.push(it);
                }
            }

        }
        while(!q.empty()){
            ans.push_back(q.front());
            q.pop();
        }
        return ans;
}
};