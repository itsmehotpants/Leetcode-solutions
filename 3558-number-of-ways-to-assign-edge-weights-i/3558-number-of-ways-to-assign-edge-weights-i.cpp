class Solution {
public:
    static constexpr long long MOD = 1e9 + 7;

    long long power(long long base, long long exp) {
        if (exp == 0)
            return 1;

        long long half = power(base, exp / 2);

        long long result = (half * half) % MOD;

        if (exp % 2 == 1) {
            result = (result * base) % MOD;
        }

        return result;
    }

    int getMaxDepth(unordered_map<int, vector<int>>& adj, int node, int parent) {

        int depth = 0;

        for (int nbr : adj[node]) {
            if (nbr == parent)
                continue;

            depth = max(depth, getMaxDepth(adj, nbr, node) + 1);
        }

        return depth;
    }

    int assignEdgeWeights(vector<vector<int>>& edges) {

        unordered_map<int, vector<int>> adj;

        for (auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        int maxDepth = getMaxDepth(adj, 1, 0);

        return power(2, maxDepth - 1);
    }
};
