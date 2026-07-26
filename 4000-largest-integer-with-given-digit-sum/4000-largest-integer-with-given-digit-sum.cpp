class Solution {
public:
    int largestInteger(int n, int s) {
       string ans ="";
        if(s==0) return 0;
        if(s>9*n) return -1;
        for(int i =0;i<n;i++){
            int m = min(9,s);
            ans+=char('0'+m);
            s-=m;
        }
        // ans = stoi(ans);
        return stoi(ans);
    }
};