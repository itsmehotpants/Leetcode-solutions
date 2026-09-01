class Solution {
public:
    int minMoves(vector<string>& c, int e) {
        int m = c.size(),n=c[0].size();
        int sr=-1,sc=-1,cnt=0;


    vector<vector<int>>id(m,vector<int>(n,-1));

        for(int i =0;i<m;i++){
            for(int j=0;j<n;j++){
                if(c[i][j]=='S'){
                    sr = i;sc=j;
                }
                if(c[i][j]=='L'){
                    id[i][j]=cnt++;
                }
            }
        }
        int masks = 1<<cnt;
        int fullMask = masks-1;

        vector<vector<vector<int>>>best;
        best.resize(m,vector<vector<int>>(n,vector<int>(masks,-1)));

        struct State{
            int r,col;
            int mask;
            int en;
            int dist;
        };

        queue<State>q;
        q.push({sr,sc,0,e,0});
        best[sr][sc][0]=e;

        int dr[]= {-1,1,0,0},dc[]={0,0,1,-1};

        while(!q.empty()){
            State cur = q.front();q.pop();
            int r= cur.r,col=cur.col,mask = cur.mask,en=cur.en,dist=cur.dist;

            if(mask==fullMask) return dist;
            if(en==0) continue;
            for(int d= 0;d<4;d++){
                int nr = r+dr[d],nc=col+dc[d];

                if(nr<0||nr>=m||nc<0||nc>=n) continue;

                if(c[nr][nc]=='X') continue;

                int newEn=en-1;
                int newMask=mask;

                if(c[nr][nc]=='L'){
                    newMask |= (1<<id[nr][nc]);
                }

                if(c[nr][nc]=='R') newEn = e;
                if(best[nr][nc][newMask]>=newEn) continue;
                best[nr][nc][newMask]=newEn;

                q.push({nr,nc,newMask,newEn,dist+1});
            }
        }
        return -1;
        
    }
};