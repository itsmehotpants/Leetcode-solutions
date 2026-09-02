class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& r, int s, int t) {
        if(s==t) return 0;
        unordered_map<int,vector<int>>mp;
        for(int i=0;i<r.size();i++){
            for(int stop:r[i]){
                mp[stop].push_back(i);
            }
        }
        vector<int>vis(r.size(),0);
        queue<int>q;
        q.push(s);
        int buses = 0;

        while(!q.empty()){
            int sz =q.size();
           
            while(sz--){
                int stop=q.front();q.pop();
                if(stop==t) return buses;
                for(int i:mp[stop]){
                    if(vis[i]) continue;
                    vis[i]=1;
                    for(int next:r[i]){
                        q.push(next);
                    }
                }
            }
             buses++;
        }
        return -1;
    }
};