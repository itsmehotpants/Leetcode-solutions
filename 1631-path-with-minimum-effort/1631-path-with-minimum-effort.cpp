#define pii pair<int,pair<int,int>>

class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& h) {
        const int dx[4] ={1,-1,0,0},dy[4]={0,0,1,-1};
        int n =h.size(),m=h[0].size();
        priority_queue<pii,vector<pii>,greater<pii>>pq;
        vector<vector<int>>dist(n,vector<int>(m,INT_MAX));
        dist[0][0]=0;
        pq.push({0,{0,0}});

        while(!pq.empty()){
            pii curr = pq.top();pq.pop();
            int d=curr.first,r=curr.second.first,c=curr.second.second;
            if(r==n-1&&c==m-1) return d;
            for(int i =0;i<4;i++){
                int nr=r+dx[i],nc=c+dy[i];
                if(nr>=0&&nc>=0&&nc<m&&nr<n){
                    int nd = max(d,abs(h[nr][nc]-h[r][c]));
                    if(nd<dist[nr][nc]){
                        dist[nr][nc]=nd;
                        pq.push({nd,{nr,nc}});
                    }
                }
            }
        }
        return 0;

    }
};