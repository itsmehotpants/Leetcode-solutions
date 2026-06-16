class Solution {
public:

int t[1001][1001];
bool isPal(int i,int j,string& s){
if(i>j) return true;
if(t[i][j]!=-1) return t[i][j];
if(s[i]==s[j]) return t[i][j]= isPal(i+1,j-1,s);
else return  t[i][j]=false;

}

    int countSubstrings(string s) {
        memset(t,-1,sizeof(t));
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