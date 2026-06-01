class Solution {
public:
    int minimumCost(vector<int>& cost) {
        // sort(cost.begin(),cost.end());
        // int sum=0;
        // for(int c:cost) sum+=c;
        // for(int i =cost.size()-3;i>=0;i-=3){
        //     sum-=cost[i];
        // }
        // return sum;
         sort(cost.rbegin(), cost.rend());

        int ans = 0;

        for(int i = 0; i < cost.size(); i++) {
            if(i % 3 != 2)
                ans += cost[i];
        }

        return ans;
    }
};