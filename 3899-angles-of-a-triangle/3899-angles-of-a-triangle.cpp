class Solution {
public:
    vector<double> internalAngles(vector<int>& s) {
        double a = s[0];
        double b = s[1];
        double c = s[2];
        if(a+b<=c || b+c<=a || c+a<=b){
            return {};
        }
       double pi=acos(-1);
        double A = acos((b*b + c*c - a*a) /(2*b*c)) *180.0/pi;
        double B = acos((a*a + c*c - b*b) /(2*a*c)) *180.0/pi;
        double C = acos((a*a + b*b - c*c) /(2*a*b)) *180.0/pi;
        vector<double> ans = {A,B,C};
        sort(ans.begin(),ans.end());
        return ans;
    }
};