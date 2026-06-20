class Solution {
public:
    long long finishTime(int n, vector<vector<int>>& edges, vector<int>& t) {
        vector<int>par(n,-1),deg(n);
        vector<long long> f(n),mn(n,1e18),mx(n);

        for(auto&e:edges){
            par[e[1]]=e[0];
            deg[e[0]]++;
        }
        queue<int>q;
        for(int i =0;i<n;i++){
            if(!deg[i]){
                f[i] =t[i];
                q.push(i);
            }
        }

        while(!q.empty()){
            int u  =q.front();q.pop();
            if(u==0) continue;

            int p =par[u];
            mn[p] = min(mn[p],f[u]);
            mx[p] =max(mx[p],f[u]);

            if(--deg[p]==0){
                f[p] = mx[p]+(mx[p]-mn[p])+t[p];
                q.push(p);
            }
        }
        return f[0];
    }
};