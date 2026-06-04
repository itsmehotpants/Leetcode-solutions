#define pii pair<int,pair<int,int>>

class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& h) {

        int n = h.size();
        int m = h[0].size();

        const int dx[4] = {1,-1,0,0};
        const int dy[4] = {0,0,1,-1};

        priority_queue<
            pii,
            vector<pii>,
            greater<pii>
        > pq;

        vector<vector<int>> dist(
            n,
            vector<int>(m, INT_MAX)
        );

        dist[0][0] = 0;

        pq.push({0,{0,0}});

        while(!pq.empty()){

            auto curr = pq.top();
            pq.pop();

            int d = curr.first;
            int r = curr.second.first;
            int c = curr.second.second;

            if(d > dist[r][c])
                continue;

            if(r == n-1 && c == m-1)
                return d;

            for(int i = 0; i < 4; i++){

                int nr = r + dx[i];
                int nc = c + dy[i];

                if(nr >= 0 && nc >= 0 &&
                   nr < n && nc < m){

                    int nd = max(
                        d,
                        abs(h[nr][nc] - h[r][c])
                    );

                    if(nd < dist[nr][nc]){

                        dist[nr][nc] = nd;

                        pq.push({nd,{nr,nc}});
                    }
                }
            }
        }

        return 0;
    }
};