class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n =grid.size(),m=grid[0].size();

        queue<pair<int,int>>q;
        int time =0;
        int fresh=0;
        for(int i=0;i<n;i++){
            for(int j =0;j<m;j++){
                if(grid[i][j]==2) q.push({i,j});
                if(grid[i][j]==1) fresh++;
            }
        }
        if(fresh==0) return 0;
        
        vector<pair<int,int>>dir= {{1,0},{-1,0},{0,1},{0,-1}};
        while(!q.empty()&& fresh>0){
            int sz =q.size();
            if(fresh==0) return 0;
             time++;

            for(int i=0;i<sz;i++){
             auto[r,c] =q.front();q.pop();
            for(auto[dr,dc]:dir){
                int nr = r+dr;
                int nc=c+dc;
            if(nr>=0&&nc>=0&&nr<n&&nc<m&&grid[nr][nc]==1){
                grid[nr][nc]=2;
                fresh--;
                q.push({nr,nc});
            }

            }
            }
        }
        return (fresh==0)?time:-1; 
    }
};