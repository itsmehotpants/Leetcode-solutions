class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& a) {
        int m = a.size()-1,n=a[0].size()-1;
        vector<int>res;
        int l = 0,top=0,r=n,bot= m;
        while(top<=bot && l<=r){
            for(int  i =l;i<=r;i++){
                res.push_back(a[top][i]);
            }
            top++;
            for(int i = top;i<=bot;i++){
                res.push_back(a[i][r]);
            }
            r--;
            if(top<=bot){
                for(int i =r;i>=l;i--){
                    res.push_back(a[bot][i]);
                }
                bot--;
            }
            if(l<=r){
                for(int i =bot;i>=top;i--){
                    res.push_back(a[i][l]);
                }
                l++;
            }
        }
        return res;
    }
};