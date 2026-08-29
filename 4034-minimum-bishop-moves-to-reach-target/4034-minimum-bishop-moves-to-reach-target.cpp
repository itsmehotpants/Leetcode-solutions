class Solution {
public:
    int minBishopMoves(vector<int>& s, vector<int>& t) {
        if((s[0]+s[1])%2!=(t[0]+t[1])%2) return -1;

        else if(abs(s[0]-t[0])==abs(s[1]-t[1])) return 1;

        return 2;
    }
};