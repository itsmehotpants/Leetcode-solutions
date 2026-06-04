class Solution {
public:

    void dfs(int n,vector<vector<int>>& conn,vector<bool>&visit){
        visit[n]=1;
        for(int i=0;i<conn.size();i++){
            if(!visit[i]&&conn[n][i]) dfs(i,conn,visit);
        }
    }
    void bfs(int n,vector<vector<int>>& conn,vector<bool>&visit){
        queue<int>q;
        q.push(n);
        visit[n]=1;
        while(!q.empty()){
            int temp =q.front();
            q.pop();
            for(int i = 0 ;i<conn.size();i++){
                if(!visit[i]&&conn[temp][i]==1){
                    q.push(i);
                    visit[i]=1;
                }
            }
        }
    }

    int findCircleNum(vector<vector<int>>& conn) {
        int ans = 0;
        int n =conn.size();
        vector<bool>visit(n);
        for(int i =0;i<n;i++){
            if(!visit[i]) {
                ans++;
                bfs(i,conn,visit);
        }
        }
        return ans;
    }
};