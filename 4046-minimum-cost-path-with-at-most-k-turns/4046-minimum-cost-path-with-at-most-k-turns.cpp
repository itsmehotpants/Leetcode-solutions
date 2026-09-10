class Solution {
public:
    int minCost(vector<vector<int>>& grid, int k) {
        int m = grid.size(), n = grid[0].size();
        if (m == 1 && n == 1) return grid[0][0];
        int dx[] = {-1, 1, 0, 0};
        int dy[] = {0, 0, -1, 1};
        
        vector<vector<vector<vector<int>>>> dist(m, vector<vector<vector<int>>>(n, 
            vector<vector<int>>(5, vector<int>(k + 1, INT_MAX))));
        
        priority_queue<tuple<int,int,int,int,int>, 
            vector<tuple<int,int,int,int,int>>, greater<>> pq;
        
        dist[0][0][4][0] = grid[0][0];
        pq.push({grid[0][0], 0, 0, 4, 0});
        
        while (!pq.empty()) {
            auto [cost, r, c, dir, turns] = pq.top();
            pq.pop();
            
            if (r == m - 1 && c == n - 1) return cost;
            if (cost > dist[r][c][dir][turns]) continue;
            
            for (int d = 0; d < 4; d++) {
                int nr = r + dx[d], nc = c + dy[d];
                if (nr < 0 || nr >= m || nc < 0 || nc >= n) continue;
                
                int nt = turns;
                if (dir != 4 && d != dir) nt++;
                if (nt > k) continue;
                
                int ncost = cost + grid[nr][nc];
                if (ncost < dist[nr][nc][d][nt]) {
                    dist[nr][nc][d][nt] = ncost;
                    pq.push({ncost, nr, nc, d, nt});
                }
            }
        }
        return -1;
    }
};