class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& a) {
        int m = a.size();
        int n = a[0].size();

        vector<vector<char>> res(n, vector<char>(m, '.'));

        for (int i = 0; i < m; i++) {
            int low = n - 1;
            for (int j = n - 1; j >= 0; j--) {
                if (a[i][j] == '#') {
                    res[low][m - 1 - i] = '#';
                    low--;
                } else if (a[i][j] == '*') {
                    res[j][m - 1 - i] = '*';
                    low = j - 1;
                }
            }
        }
        return res;
    }
};