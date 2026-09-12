class Solution {
public:
    int n;

    struct Node {
        long long score;
        vector<int> idxs;

        Node(long long s = LLONG_MIN) : score(s) {}
    };

    vector<int> nextIdx;
    vector<vector<Node>> dp;

    int findNext(vector<vector<int>>& t, int r) {
        int l = 0, h = n - 1;
        int res = n;

        while (l <= h) {
            int mid = l + (h - l) / 2;

            // Need interval whose start > current end
            if (t[mid][0] > r) {
                res = mid;
                h = mid - 1;
            } else {
                l = mid + 1;
            }
        }

        return res;
    }

    Node solve(vector<vector<int>>& t, int i, int k) {
        if (k == 0 || i >= n) {
            return Node(0);   
        }

        if (dp[i][k].score != LLONG_MIN) {
            return dp[i][k];
        }

        // Option 1: skip current interval
        Node skip = solve(t, i + 1, k);

        // Option 2: take current interval
        int wt = t[i][2];
        int idx = t[i][3];
        int j = nextIdx[i];

        Node temp = solve(t, j, k - 1);

        Node take;
        take.score = temp.score + wt;
        take.idxs = temp.idxs;
        take.idxs.push_back(idx);

        // Lexicographically smallest indices
        sort(take.idxs.begin(), take.idxs.end());

        Node res;

        if (skip.score > take.score) {
            res = skip;
        } 
        else if (skip.score < take.score) {
            res = take;
        } 
        else {
            res = (skip.idxs < take.idxs) ? skip : take;
        }

        return dp[i][k] = res;
    }

    vector<int> maximumWeight(vector<vector<int>>& t) {
        n = t.size();

        for (int i = 0; i < n; i++) {
            t[i].push_back(i); 
        }

        sort(t.begin(), t.end());

        nextIdx.resize(n);

        for (int i = 0; i < n; i++) {
            int end = t[i][1];
            nextIdx[i] = findNext(t, end);
        }

        int k = 4;

        dp.assign(n + 1, vector<Node>(k + 1));

        return solve(t, 0, k).idxs;
    }
};