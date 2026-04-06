class Solution {
public:
    int robotSim(vector<int>& cmd, vector<vector<int>>& obs) {
        int n = cmd.size();
        int len = obs.size();

        set<pair<int, int>> s;
        for(int i=0; i<len; i++){
            s.insert({obs[i][0], obs[i][1]});
        }

        char dir[4] = {'N','E','S','W'};
        int d = 0;
        int x = 0, y = 0;
        int dis = 0;

        for(int i=0; i<n; i++){
            if(cmd[i] == -1){
                d = (d + 1) % 4;
            }
            else if(cmd[i] == -2){
                d = (d + 3) % 4;
            }
            else{
                if(dir[d] == 'N'){
                    for(int j=0; j<cmd[i]; j++){
                        if(s.count({x,y+1})) break;
                        y++;
                    }
                }
                else if(dir[d] == 'E'){
                    for(int j=0; j<cmd[i]; j++){
                        if(s.count({x+1,y})) break;
                        x++;
                    }
                }
                else if(dir[d] == 'S'){
                    for(int j=0; j<cmd[i]; j++){
                        if(s.count({x,y-1})) break;
                        y--;
                    }
                }
                else{
                    for(int j=0; j<cmd[i]; j++){
                        if(s.count({x-1,y})) break;
                        x--;
                    }
                }

                dis = max(dis, x*x + y*y);
            }
        }

        return dis;
    }
};