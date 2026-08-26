class Solution {
public:
    int carFleet(int x, vector<int>& pos, vector<int>& v) {
        int n =pos.size();
        vector<pair<int,int>>cars(n);
        for(int i=0;i<n;i++) cars[i] = {pos[i],v[i]};

        sort(cars.begin(),cars.end());
        int ans=0;
        double pre  =-1.0;
        for(int i =n-1;i>=0;i--){
            double t = 1.0*(x-cars[i].first)/cars[i].second;
            if(t>pre){
                ans++;
                pre=t;
            }
        }
        return ans;
    }
};