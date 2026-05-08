class Solution {
public:
    int minJumps(vector<int>& nums) {
        int n=nums.size();
        int mx=*max_element(nums.begin(),nums.end());
        vector<bool>prime(mx+1,true);
        prime[0]=prime[1]=false;
        for(long long i=2;i*i<=mx;i++){
            if(prime[i]){
                for(long long j=i*i;j<=mx;j+=i)prime[j]=false;
            }
        }
        vector<vector<int>>pos(mx+1);
        for(int i=0;i<n;i++){
            pos[nums[i]].push_back(i);
        }
        queue<pair<int,int>>q;
        vector<int>vis(n);
        vis[0]=1;
        q.push({0,0});
        int d=0;

        while(!q.empty()){
            auto it=q.front();
            q.pop();
            int idx=it.first;
            int dist=it.second;
            if(idx==n-1)return dist;

            if(idx+1<n&&!vis[idx+1]){
                vis[idx+1]=1;
                q.push({idx+1,dist+1});
            }
            if(idx-1>=0&&!vis[idx-1]){
                vis[idx-1]=1;
                q.push({idx-1,dist+1});
            }
            if(prime[nums[idx]]){
                int p=nums[idx];
                for(int i=p;i<=mx;i+=p){
                    for(int j:pos[i]){
                        if(!vis[j]){
                            q.push({j,dist+1});
                            vis[j]=1;
                        }
                    }
                    pos[i].clear();
                }prime[p]=false;
            }
        }return n-1;
    }
};