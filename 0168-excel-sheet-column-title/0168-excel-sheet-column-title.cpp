class Solution {
public:
    string convertToTitle(int c) {
        string res="";
        while(c){
            c--;
            char s ='A' + c%26;
            res =s+res;
            c/=26;
        }
        return res;
    }
};