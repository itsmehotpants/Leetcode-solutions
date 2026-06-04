class Solution {
public:
    int findTheCity(int n,
                    vector<vector<int>>& edges,
                    int dth) {

        int ans = -1;
        int minReach = 1e9;

        for(int src = 0; src < n; src++) {

            vector<int> dist(n, 1e9);

            dist[src] = 0;

            for(int i = 1; i <= n - 1; i++) {

                for(auto &e : edges) {

                    int u = e[0];
                    int v = e[1];
                    int wt = e[2];

                    if(dist[u] != 1e9 &&
                       dist[u] + wt < dist[v]) {

                        dist[v] = dist[u] + wt;
                    }

                    if(dist[v] != 1e9 &&
                       dist[v] + wt < dist[u]) {

                        dist[u] = dist[v] + wt;
                    }
                }
            }

            int cnt = 0;

            for(int i = 0; i < n; i++) {

                if(dist[i] <= dth)
                    cnt++;
            }

            if(cnt <= minReach) {

                minReach = cnt;
                ans = src;
            }
        }

        return ans;
    }
};