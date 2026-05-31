class Solution {
public:
    int minJumps(vector<int>& arr) {
        int n =arr.size();
        unordered_map<int,vector<int>>mp;
        vector<bool>visit(n,false);
        for(int i =0;i<n;i++){
            mp[arr[i]].push_back(i);
        }
        queue<int>q;
        q.push(0);
        visit[0]=true;
        int steps=0;
        while(!q.empty()){
            int sz=q.size();
            while(sz--){
                int curr=q.front();
                q.pop();
                int l =curr-1,r=curr+1;
                if(curr==n-1) return steps;
                if(l>=0 &&!visit[l]){
                    q.push(l);
                    visit[l]=true;
                }
                if(r<=n-1&&!visit[r]){
                    q.push(r);
                    visit[r]=true;

                }
                for(int &idx:mp[arr[curr]]){
                    if(!visit[idx]){
                        q.push(idx);
                        visit[idx]=true;

                    }
                }
                mp.erase(arr[curr]);

            }
            steps++;
        }
        return -1;
    }
};