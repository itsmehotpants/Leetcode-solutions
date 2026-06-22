class Solution {
public:

    bool isValid(string &s1, string &s2) {
        vector<int> freq(26, 0);

        for(char c : s1) {
            if(freq[c-'a']) return false;
            freq[c-'a']++;
        }

        for(char c : s2) {
            if(freq[c-'a']) return false;
            freq[c-'a']++;
        }

        return true;
    }

    int solve(int i, string temp, vector<string>& arr) {
        if(i == arr.size()) return temp.length();

        int exclude = solve(i+1, temp, arr);

        int include = 0;
        if(isValid(temp, arr[i])) {
            include = solve(i+1, temp + arr[i], arr);
        }

        return max(include, exclude);
    }

    int maxLength(vector<string>& arr) {
        string temp = "";
        return solve(0, temp, arr);
    }
};