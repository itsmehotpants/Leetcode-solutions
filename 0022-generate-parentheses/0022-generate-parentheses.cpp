class Solution {
public:

void f(int n ,int l,int r,string &temp,vector<string>& ans){
    if(l+r==2*n){
        ans.push_back(temp);
        return;

    }
    if(l<n){
        temp.push_back('(');
        f(n,l+1,r,temp,ans);
        temp.pop_back();
    }
    if(r<l){
        temp.push_back(')');
        f(n,l,r+1,temp,ans);
        temp.pop_back(); 
    }
}
    vector<string> generateParenthesis(int n) {
        int l =0,r=0;
    vector<string>ans;
    string temp;
f(n,l,r,temp,ans);
return ans;
    }
};