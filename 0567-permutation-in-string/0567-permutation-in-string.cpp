class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if (s1.length() > s2.length()) return false;

        vector<int> f1(26, 0), f2(26, 0);
        for (char c : s1) f1[c - 'a']++;
        for (int i = 0; i < s1.length(); i++) f2[s2[i] - 'a']++;

        if (f1 == f2) return true;

        for (int i = s1.length(); i < s2.length(); i++) {
            f2[s2[i] - 'a']++;
            f2[s2[i - s1.length()] - 'a']--;
            if (f1 == f2) return true;
        }

        return false;
    }
};