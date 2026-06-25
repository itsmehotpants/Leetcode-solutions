class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        unordered_set<string>dead(deadends.begin(),deadends.end());
        if(dead.count("0000")) return -1;
        queue<pair<string,int>>q;
        q.push({"0000",0});
        unordered_set<string>vis;
        vis.insert("0000");
        while(!q.empty()){
            auto [curr,moves]= q.front();
            q.pop();
            if(curr==target) return moves;
            for(int i =0;i<4;i++){
                for(int delta:{-1,1}){
                    int new_dig = (curr[i]-'0'+delta+10)%10;
                    string new_comb =curr;
                    new_comb[i] = new_dig+'0';

                    if(vis.find(new_comb)==vis.end()&&dead.find(new_comb)==dead.end()){
                        vis.insert(new_comb);
                        q.push({new_comb,moves+1});
                    }
                }
            }
        }
        return -1;
    }
};