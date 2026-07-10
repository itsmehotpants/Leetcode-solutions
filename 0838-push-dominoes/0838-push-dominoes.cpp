class Solution {
public:
    string pushDominoes(string d) {
        int n = d.size();

        vector<int> leftR(n), rightL(n);

        for (int i = 0; i < n; i++) {
            if (d[i] == 'R')
                leftR[i] = i;
            else if (d[i] == '.')
                leftR[i] = (i > 0 ? leftR[i - 1] : -1);
            else
                leftR[i] = -1;
        }

        for (int i = n - 1; i >= 0; i--) {
            if (d[i] == 'L')
                rightL[i] = i;
            else if (d[i] == '.')
                rightL[i] = (i + 1 < n ? rightL[i + 1] : -1);
            else
                rightL[i] = -1;
        }

        string res = d;

        for (int i = 0; i < n; i++) {

            if (d[i] != '.') continue;

            if (leftR[i] == -1 && rightL[i] == -1)
                res[i] = '.';
            else if (leftR[i] == -1)
                res[i] = 'L';
            else if (rightL[i] == -1)
                res[i] = 'R';
            else {
                int distR = i - leftR[i];
                int distL = rightL[i] - i;

                if (distR == distL)
                    res[i] = '.';
                else if (distR < distL)
                    res[i] = 'R';
                else
                    res[i] = 'L';
            }
        }

        return res;
    }
};