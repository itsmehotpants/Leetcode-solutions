class Solution {
public:
//int dx[]={1,0,1},dy[]={0,1,1};
    vector<int> pathsWithMaxScore(vector<string>& board) {
        int n =board.size();
    const int mod =1e9+7;

    vector<vector<int>>sum(n,vector<int>(n,-1));
    vector<vector<int>>ways(n,vector<int>(n,0));

    sum[n-1][n-1]=0;
    ways[n-1][n-1]=1;

    for(int i =n-1;i>=0;i--){
        for(int j =n-1;j>=0;j--){
            if(board[i][j]=='X') continue;
            if(i==n-1&&j==n-1) continue;
            int dx[3]={1,0,1},dy[3]={0,1,1};
            int best =-1,cnt=0;
            for(int k=0;k<3;k++){
                int ni =i+dx[k],nj=j+dy[k];
                if(ni>=n||nj>=n||sum[ni][nj]==-1) continue;

                if(sum[ni][nj]>best){
                    best = sum[ni][nj];
                    cnt = ways[ni][nj];
                }
                else if(sum[ni][nj]==best){
                    cnt=(cnt+ways[ni][nj])%mod;

                }
            }
            if(best==-1) continue;
            int val =(board[i][j]-'E'==0)?0:(board[i][j]-'0');
            sum[i][j]=best+val;
            ways[i][j]=cnt;

        }
    }
    if(sum[0][0]==-1) return {0,0};
    return{sum[0][0],ways[0][0]};


    }
};