class Solution {
public:
    int passwordStrength(string pass) {
        unordered_set<char> st(pass.begin(),pass.end());
        int ans=0;
        for(char ch:st){
            if(ch>='a' && ch<='z') ans+=1;
            else if(ch>='A' && ch<='Z') ans+=2;
            else if(ch>='0' && ch<='9') ans+=3;
            else ans+=5;
        }
        return ans;
    }
};