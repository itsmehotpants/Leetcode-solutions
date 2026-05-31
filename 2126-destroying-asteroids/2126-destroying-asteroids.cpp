class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& ast) {
        sort(ast.begin(),ast.end());
        long long mass1 =mass;
        bool ans=true;
        for(int i =0;i<ast.size();i++){
            if(mass1>=ast[i]) mass1+=ast[i];
            else return false;
        }
        return true;
    }
};