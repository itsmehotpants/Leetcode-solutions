class Solution {
public:
    string answerString(string word, int f) {
        if (f == 1) return word;

        int n = word.size();
        int maxLen = n - f + 1;

        string ans = "";

        for (int i = 0; i < n; i++) {
            string cur = word.substr(i, min(maxLen, n - i));
            if (cur > ans)
                ans = cur;
        }

        return ans;
    }
};