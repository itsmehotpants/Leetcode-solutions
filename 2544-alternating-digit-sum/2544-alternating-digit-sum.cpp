class Solution {
public:
    int alternateDigitSum(int n) {
        string s = to_string(n);

        int mul = 1,ans = 0;

        for(char ch: s){
            ans += (ch-'0')*mul;
            mul*=-1;
        }
        return ans;
    }
};