class Solution {
public:
string smallestPalindrome(string s) {
    int n = s.size();
    string half = s.substr(0, n / 2);

    sort(half.begin(), half.end());

    string ans = half;
    if (n & 1)
        ans += s[n / 2];

    reverse(half.begin(), half.end());
    ans += half;

    return ans;
}
};