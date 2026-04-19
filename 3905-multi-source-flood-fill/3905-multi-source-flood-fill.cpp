class Solution {
public:
    vector<vector<int>> colorGrid(int n, int m, vector<vector<int>>& src) {
     vector<vector<int>> g(n,vector<int>(m,0));
        vector<vector<int>> d(n,vector<int>(m,1e9));
queue<tuple<int,int,int>> q;

        for(auto &s:src){
            int r=s[0],c=s[1],col=s[2];
            g[r][c]=col;
            d[r][c]=0;
            q.push({r,c,col});
        }
        int dr[4]={-1,1,0,0},dc[4]={0,0,-1,1};
        while(!q.empty()){
            auto[r,c,col] = q.front();q.pop();
            for(int k=0;k<4;k++){
                int nr = r+dr[k],nc = c+dc[k];
              if(nr<0||nc<0||nr>=n||nc>=m) continue;

                if(d[nr][nc]>d[r][c]+1 ){
                    d[nr][nc]=d[r][c]+1;
                    g[nr][nc]=col;
                    q.push({nr,nc,col});
                }
                else if(d[nr][nc]==d[r][c]+1 && g[nr][nc]<col ){
                
                    g[nr][nc]=col;
                    q.push({nr,nc,col});
                }
            }
        }
        return g;
    }
};