class Solution {
public:
    bool judgeCircle(string s) {
        int L=0, R=0, U=0, D=0;

        for(char c : s){
            if(c=='L') L++;
            else if(c=='R') R++;
            else if(c=='U') U++;
            else if(c=='D') D++;
        }

        return (L==R && U==D);
    }
};