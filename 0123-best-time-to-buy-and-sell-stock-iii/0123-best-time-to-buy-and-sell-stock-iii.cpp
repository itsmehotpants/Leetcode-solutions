class Solution {
public:
    int maxProfit(vector<int>& a) {
     int b1 =INT_MAX,b2 = INT_MAX;
     int p1=INT_MIN;
     int p2=INT_MIN;
     for(int i = 0;i<a.size();i++){
        b1= min(a[i],b1);
        p1 = max(p1,a[i]-b1);
        b2 = min(b2,a[i]-p1);
        p2 = max(p2,a[i]-b2);
     }
     return p2;
    }
};