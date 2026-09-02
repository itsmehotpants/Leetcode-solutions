class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n  =grid.size();
        if(grid[0][0]!=0 || grid[n-1][n-1]!=0) return -1;

        vector<int>dr = {-1,-1,-1,0,0,1,1,1};
        vector<int>dc  = {-1,1,0,1,-1,-1,1,0};
        queue<pair<int,int>>q;
        q.push({0,0});

        grid[0][0]=1;
        while(!q.empty()){
            auto[r,c]=q.front();q.pop();

            int dist = grid[r][c];

            if(r==n-1&&c==n-1) return dist;

            for (int d = 0; d < 8; d++) {

                int nr = r + dr[d];
                int nc = c + dc[d];

                if (nr >= 0 && nr < n &&
                    nc >= 0 && nc < n &&
                    grid[nr][nc] == 0) {

                    grid[nr][nc] = dist + 1;

                    q.push({nr, nc});
                }
            }
        }
        return -1;
    }
};