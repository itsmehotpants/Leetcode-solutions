class Solution {
public:
    int numberOfSubstrings(string s) {
        int i, n=s.size();
        int cnt=0;
        int seen[3] = {-1, -1, -1};

        for(i=0; i<n; i++){
            seen[s[i]-'a'] = i;
            cnt += 1 + min(seen[0], min(seen[1], seen[2]));
        }

        return cnt;
    }
};