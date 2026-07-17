//brute
class Solution {
public:
    string decodeString(string s) {
        while (s.find('[') != string::npos) {

            int close = s.find(']');

            // Find matching '['
            int open = close;
            while (s[open] != '[') open--;

            // Find the complete number before '['
            int numStart = open - 1;
            while (numStart >= 0 && isdigit(s[numStart])) numStart--;
            numStart++;

            int k = stoi(s.substr(numStart, open - numStart));
            string body = s.substr(open + 1, close - open - 1);

            string expanded = "";
            while (k--) expanded += body;

            s = s.substr(0, numStart) + expanded + s.substr(close + 1);
        }

        return s;
    }
};