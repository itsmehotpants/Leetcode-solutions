class Solution {
public:
    int maxProfit(vector<int>& a) {
        int n =a.size();
        int minm = INT_MAX,ans= 0,pst=0;
        for(int i =0;i<n;i++){
            if(a[i]<minm) minm=a[i];
            pst = a[i]-minm;
            if(pst>ans) ans=pst;

            
        }
        return ans;
    }
};