class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        if (mat.empty() || mat[0].empty())
            return {};

        int m = mat.size(), n = mat[0].size();

        queue<pair<int,int>>q;
        int maxm =m*n;
        for(int i =0;i<m;i++){
            for(int j =0;j<n;j++){
                if(mat[i][j]==0) q.push({i,j});
                else mat[i][j] = maxm;
            }
        }

                vector<pair<int, int>> dirs = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        while(!q.empty()){
            auto [row,col] = q.front();
            q.pop();
            for(auto [dr,dc]:dirs){
                int r=row+dr,c=col+dc;
                if(r>=0&&c>=0&&r<m&&c<n&&mat[r][c]>mat[row][col]+1){
                    q.push({r,c});
                    mat[r][c] = mat[row][col]+1;
                }
            }
        }
        return mat;
    }
};