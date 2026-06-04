class Solution {
        vector<pair<int,int>> dir = {{1,0},{-1,0},{0,1},{0,-1}};

    void dfs(vector<vector<int>>& img, int color, int i, int j, int val){
        if(i<0 || j<0 || i>=img.size() || j>=img[i].size() || img[i][j]!=val || img[i][j] == color ) return;
        img[i][j]=color;
        // dfs(img, color, i+1, j, val);
        // dfs(img, color, i-1, j, val);
        // dfs(img, color, i, j-1, val);
        // dfs(img, color, i, j+1, val);
        for(auto [u,v]:dir){
            dfs(img,color,i+u,j+v,val);
        }
    
    }
public:
    vector<vector<int>> floodFill(vector<vector<int>>& img, int sr, int sc, int color) {
        int val = img[sr][sc];
        dfs(img, color, sr, sc, val);
        return img;
    }
};
