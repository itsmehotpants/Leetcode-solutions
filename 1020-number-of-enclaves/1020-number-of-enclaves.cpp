class DSU
{
public:
    vector<int> parent, rank;

    DSU(int n)
    {
        parent.resize(n);
        rank.resize(n, 0);

        for(int i = 0; i < n; i++)
            parent[i] = i;
    }

    int find(int x)
    {
        if(parent[x] == x)
            return x;

        return parent[x] = find(parent[x]);
    }

    void unite(int x, int y)
    {
        int px = find(x);
        int py = find(y);

        if(px == py)
            return;

        if(rank[px] < rank[py])
        {
            parent[px] = py;
        }
        else if(rank[px] > rank[py])
        {
            parent[py] = px;
        }
        else
        {
            parent[py] = px;
            rank[px]++;
        }
    }
};

class Solution {
public:

    // ================= DFS =================

    void dfs(vector<vector<int>>& board, int i, int j)
    {
        int n = board.size();
        int m = board[0].size();

        if(i < 0 || j < 0 || i >= n || j >= m)
            return;

        if(board[i][j] != 1)
            return;

        board[i][j] = 0;

        dfs(board, i + 1, j);
        dfs(board, i - 1, j);
        dfs(board, i, j + 1);
        dfs(board, i, j - 1);
    }

    // ================= BFS =================

    void bfs(vector<vector<int>>& board, int i, int j)
    {
        int n = board.size();
        int m = board[0].size();

        queue<pair<int,int>> q;
        q.push({i, j});

        board[i][j] = 0;

        int dx[] = {1,-1,0,0};
        int dy[] = {0,0,1,-1};

        while(!q.empty())
        {
            auto [x, y] = q.front();
            q.pop();

            for(int k = 0; k < 4; k++)
            {
                int nx = x + dx[k];
                int ny = y + dy[k];

                if(nx >= 0 && ny >= 0 && nx < n && ny < m &&
                   board[nx][ny] == 1)
                {
                    board[nx][ny] = 0;
                    q.push({nx, ny});
                }
            }
        }
    }

    int numEnclaves(vector<vector<int>>& board) {

        // =====================================================
        // METHOD 1 : DFS
        // =====================================================

        /*
        int n = board.size();
        int m = board[0].size();

        if(n == 1 || m == 1)
            return 0;

        for(int i = 0; i < n; i++)
        {
            if(board[i][0] == 1)
                dfs(board, i, 0);

            if(board[i][m-1] == 1)
                dfs(board, i, m-1);
        }

        for(int j = 0; j < m; j++)
        {
            if(board[0][j] == 1)
                dfs(board, 0, j);

            if(board[n-1][j] == 1)
                dfs(board, n-1, j);
        }

        int ans = 0;

        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                if(board[i][j] == 1)
                    ans++;
            }
        }

        return ans;
        */




        // =====================================================
        // METHOD 2 : BFS
        // =====================================================

        /*
        int n = board.size();
        int m = board[0].size();

        if(n == 1 || m == 1)
            return 0;

        for(int i = 0; i < n; i++)
        {
            if(board[i][0] == 1)
                bfs(board, i, 0);

            if(board[i][m-1] == 1)
                bfs(board, i, m-1);
        }

        for(int j = 0; j < m; j++)
        {
            if(board[0][j] == 1)
                bfs(board, 0, j);

            if(board[n-1][j] == 1)
                bfs(board, n-1, j);
        }

        int ans = 0;

        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                if(board[i][j] == 1)
                    ans++;
            }
        }

        return ans;
        */




        // =====================================================
        // METHOD 3 : Multi-Source BFS
        // =====================================================

        /*
        int n = board.size();
        int m = board[0].size();

        if(n == 1 || m == 1)
            return 0;

        queue<pair<int,int>> q;

        for(int i = 0; i < n; i++)
        {
            if(board[i][0] == 1)
            {
                q.push({i, 0});
                board[i][0] = 0;
            }

            if(board[i][m-1] == 1)
            {
                q.push({i, m-1});
                board[i][m-1] = 0;
            }
        }

        for(int j = 0; j < m; j++)
        {
            if(board[0][j] == 1)
            {
                q.push({0, j});
                board[0][j] = 0;
            }

            if(board[n-1][j] == 1)
            {
                q.push({n-1, j});
                board[n-1][j] = 0;
            }
        }

        int dx[] = {1,-1,0,0};
        int dy[] = {0,0,1,-1};

        while(!q.empty())
        {
            auto [x, y] = q.front();
            q.pop();

            for(int k = 0; k < 4; k++)
            {
                int nx = x + dx[k];
                int ny = y + dy[k];

                if(nx >= 0 && ny >= 0 && nx < n && ny < m &&
                   board[nx][ny] == 1)
                {
                    board[nx][ny] = 0;
                    q.push({nx, ny});
                }
            }
        }

        int ans = 0;

        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                if(board[i][j] == 1)
                    ans++;
            }
        }

        return ans;
        */




        // =====================================================
        // METHOD 4 : DSU
        // =====================================================

        int n = board.size();
        int m = board[0].size();

        DSU dsu(n * m + 1);

        int dummy = n * m;

        auto node = [&](int x, int y)
        {
            return x * m + y;
        };

        int dx[] = {1,-1,0,0};
        int dy[] = {0,0,1,-1};

        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                if(board[i][j] != 1)
                    continue;

                if(i == 0 || j == 0 || i == n-1 || j == m-1)
                {
                    dsu.unite(node(i,j), dummy);
                }

                for(int k = 0; k < 4; k++)
                {
                    int nx = i + dx[k];
                    int ny = j + dy[k];

                    if(nx >= 0 && ny >= 0 &&
                       nx < n && ny < m &&
                       board[nx][ny] == 1)
                    {
                        dsu.unite(node(i,j), node(nx,ny));
                    }
                }
            }
        }

        int ans = 0;

        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                if(board[i][j] == 1 &&
                   dsu.find(node(i,j)) != dsu.find(dummy))
                {
                    ans++;
                }
            }
        }

        return ans;
    }
};