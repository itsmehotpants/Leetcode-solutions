class Solution {
public:

bool isPal(int i,int j,string& s){
if(i>j) return true;
if(s[i]==s[j]) return isPal(i+1,j-1,s);
else return false;

}

    int countSubstrings(string s) {
        int n =s.length();
        int cnt=0;
        for(int i =0;i<n;i++){
            for(int j =i;j<n;j++){
                if(isPal(i,j,s)) cnt++;
            }
        }
        return cnt;
    }
};