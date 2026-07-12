class Solution {
    
public:
    int f(string &s){
return stoi(s.substr(0,2))*3600+stoi(s.substr(3,2))*60+stoi(s.substr(6,2));
    }
    int secondsBetweenTimes(string s, string e) {
        return f(e)-f(s);
    }
};