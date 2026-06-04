class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
    vector<vector<pair<int, int>>> adj(n);
    vector<long> time(n, 0), cnt(n, 1);
    for (auto &r : roads) {
        adj[r[0]].push_back({r[1], r[2]});
        adj[r[1]].push_back({r[0], r[2]});
    }
    priority_queue<pair<long, int>, vector<pair<long, int>>, greater<>> pq;
    pq.push({0, 0});
    while (!pq.empty()) {
        auto[dist, i] = pq.top(); pq.pop();
            for (auto [j, t] : adj[i]) {
                if (time[j] == 0 || time[j] >= dist + t) {
                    if (time[j] == dist + t)
                        cnt[j] = (cnt[j] + cnt[i]) % 1000000007;
                    else {
                        time[j] = dist + t;
                        cnt[j] = cnt[i];
                        pq.push({time[j], j});
                    }
                }
            }
    }
    return cnt[n - 1];

    }
};