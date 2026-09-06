class Solution {
public:
    int countRotations(string s, int k) {
        int pair=0,n=s.size();
        for(int i=1; i<n; i++){
            if(s[i]==s[i-1]){
                pair++;
            }
        }
        if(s[0]==s[n-1]){
            pair++;
        }
        if(k==pair-1){
            return pair;
        }else if(k==pair){
            return n-pair;
        }
        return 0;
    }
};