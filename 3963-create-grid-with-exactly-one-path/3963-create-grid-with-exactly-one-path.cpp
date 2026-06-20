class Solution {
public:
    vector<string> createGrid(int m, int n) {
     vector<string> a(m,string(n,'#'));
        for(int j =0;j<n;j++) a[0][j]='.';
        for(int i =0;i<m;i++) a[i][n-1] = '.';
        return a;
    }
};