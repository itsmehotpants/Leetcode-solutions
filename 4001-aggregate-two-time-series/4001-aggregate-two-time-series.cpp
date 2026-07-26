class Solution {
public:
    vector<vector<int>> aggregateTimeSeries(vector<vector<int>>& s1, vector<vector<int>>& s2) {
int n =s1.size(),m=s2.size();
        vector<vector<int>>ans;
        int i=0,j=0,p1=0,p2=0;

        while(i<n ||j<m){
            int  t;
             if(j==m || (i<n && s1[i][0]<s2[j][0])){
                 t = s1[i][0];
                 i++;
             }
           else if(i==n || s2[j][0]<s1[i][0]){
                t= s2[j][0];
                j++;
            }
            else{
                t = s1[i][0];
                i++;j++;
            }
        
        while(p1<n && s1[p1][0]<t) p1++;
        while(p2<m && s2[p2][0]<t) p2++;

        int a1 = (p1<n)?s1[p1][1]:0;
        int a2 = (p2<m)?s2[p2][1]:0;

        ans.push_back({t,a1+a2});
        }
        return ans;
    }
};