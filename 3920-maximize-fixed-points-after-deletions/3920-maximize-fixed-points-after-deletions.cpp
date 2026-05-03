class Solution {
public:
    int maxFixedPoints(vector<int>& nums) {
        int n =nums.size();
        vector<pair<int,int>> v;
        for(int i=0;i<n;i++){
            if(nums[i]>i) continue;
            else v.push_back({i-nums[i],nums[i]});
        }
            sort(v.begin(),v.end());

                    vector<int> lis;

            for(auto &[d,x]:v){
            auto it = lower_bound(lis.begin(),lis.end(),x);
            if(it==lis.end()) lis.push_back(x);
            else *it=x;
        
        }
        return lis.size();
    }
};