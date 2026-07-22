class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& a, int sr, int sc, int col) {
        int n =a.size(),m=a[0].size();
        int og = a[sr][sc];
        if(og==col) return a;


        vector<pair<int,int>>dis = {{1,0},{0,1},{-1,0},{0,-1}};
        queue<pair<int,int>>q;
        //vector<vector<int>>adj;
        q.push({sr,sc});
        while(!q.empty()){
            auto [x,y] =q.front();q.pop();
            a[x][y]=col;
            for(auto&dir:dis){
                int nx =x+dir.first;
                int ny =y+dir.second;

                if(nx>=0&&nx<n&&ny>=0&&ny<m&&a[nx][ny]==og){
                    a[nx][ny]=col;
                    q.push({nx,ny});
                } 
            }
        } 
        return a;
    }
};